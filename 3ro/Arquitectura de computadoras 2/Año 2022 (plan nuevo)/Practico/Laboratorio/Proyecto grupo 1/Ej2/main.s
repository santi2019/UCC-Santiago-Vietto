	.text
	.org 0x0000

	// Setup Frame Buffer
	.equ SCREEN_X, 512
	.equ SCREEN_Y, 512
	.equ BITS_PER_PIXEL, 16
	.equ MAIL_BASE,  0xB880 // Mailbox Base Address
	.equ MAIL_WRITE, 0x20 // Mailbox Write Register
	.equ MAIL_TAGS,  0x8    // Mailbox Channel 8: Tags (ARM to VC)
	.equ PERIPHERAL_BASE, 0x3F000000 // Peripheral Base Address
		
	.equ Allocate_Buffer,      0x00040001 // Frame Buffer: Allocate Buffer (Response: Frame Buffer Base Address In Bytes, Frame Buffer Size In Bytes)

	.equ Set_Physical_Display, 0x00048003 // Frame Buffer: Set Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
	.equ Set_Virtual_Buffer,   0x00048004 // Frame Buffer: Set Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
	.equ Set_Depth,            0x00048005 // Frame Buffer: Set Depth (Response: Bits Per Pixel)
	.equ Set_Virtual_Offset,   0x00048009 // Frame Buffer: Set Virtual Offset (Response: X In Pixels, Y In Pixels)
	.equ Set_Palette,          0x0004800B // Frame Buffer: Set Palette (Response: RGBA Palette Values (Index 0 To 255))
	
	
	.equ GPIO_BASE, 	0x200000  	// Base de los GPIO desde la dirección PERIPHERAL_BASE.
	.equ GPIO_GPFSEL1, 	0x4    		// GPIO Function Select 1
	.equ GPIO_GPLEV0, 	0x34    	// GPIO Pin Level 0 o los niveles de los pines inferiores (0-31)
	
		


// Return CPU ID (0..3) Of The CPU Executed On
	mrs x0,MPIDR_EL1 // X0 = Multiprocessor Affinity Register (MPIDR)
	ands x0,x0,3 // X0 = CPU ID (Bits 0..1)
	b.ne CoreLoop // IF (CPU ID != 0) Branch To Infinite Loop (Core ID 1..3)

// Core 0 Init the framebuffer
FB_Init:
	ldr x0, =(FB_STRUCT + MAIL_TAGS)
	ldr x1, =MAIL_BASE
	ldr x2, =FB_POINTER
	orr x1,x1,PERIPHERAL_BASE
	str w0,[x1,MAIL_WRITE + MAIL_TAGS] // Mail Box Write
	ldr w0,[x2] // W0 = Frame Buffer Pointer
	cbz w0,FB_Init // IF (Frame Buffer Pointer == Zero) Re-Initialize Frame Buffer
	and w0,w0,0x3FFFFFFF // Convert Mail Box Frame Buffer Pointer From BUS Address To Physical Address ($CXXXXXXX -> $3XXXXXXX)
	str w0,[x2] // Store Frame Buffer Pointer Physical Address

	// Core 0 branch to app	
	b app	

	// Infinite Loop For Core 1, 2 and 3	
CoreLoop: 
	b CoreLoop

.align 16
FB_STRUCT: // Mailbox Property Interface Buffer Structure
	.word FB_STRUCT_END - FB_STRUCT // Buffer Size In Bytes (Including The Header Values, The End Tag And Padding)
	.word 0x00000000 // Buffer Request/Response Code
	// Request Codes: $00000000 Process Request Response Codes: $80000000 Request Successful, $80000001 Partial Response
	// Sequence Of Concatenated Tags
	.word Set_Physical_Display // Tag Identifier
	.word 0x00000008 // Value Buffer Size In Bytes
	.word 0x00000008 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
	.word SCREEN_X // Value Buffer
	.word SCREEN_Y // Value Buffer

	.word Set_Virtual_Buffer // Tag Identifier
	.word 0x00000008 // Value Buffer Size In Bytes
	.word 0x00000008 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
	.word SCREEN_X // Value Buffer
	.word SCREEN_Y // Value Buffer

	.word Set_Depth // Tag Identifier
	.word 0x00000004 // Value Buffer Size In Bytes
	.word 0x00000004 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
	.word BITS_PER_PIXEL // Value Buffer

	.word Set_Virtual_Offset // Tag Identifier
	.word 0x00000008 // Value Buffer Size In Bytes
	.word 0x00000008 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
FB_OFFSET_X:
	.word 0 // Value Buffer
FB_OFFSET_Y:
	.word 0 // Value Buffer

	.word Set_Palette // Tag Identifier
	.word 0x00000010 // Value Buffer Size In Bytes
	.word 0x00000010 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
	.word 0 // Value Buffer (Offset: First Palette Index To Set (0-255))
	.word 2 // Value Buffer (Length: Number Of Palette Entries To Set (1-256))
FB_PAL:
	.word 0x00000000,0xFFFFFFFF // RGBA Palette Values (Offset To Offset+Length-1)

	.word Allocate_Buffer // Tag Identifier
	.word 0x00000008 // Value Buffer Size In Bytes
	.word 0x00000008 // 1 bit (MSB) Request/Response Indicator (0=Request, 1=Response), 31 bits (LSB) Value Length In Bytes
FB_POINTER:
	.word 0 // Value Buffer
	.word 0 // Value Buffer

	.word 0x00000000 // $0 (End Tag)
FB_STRUCT_END:

