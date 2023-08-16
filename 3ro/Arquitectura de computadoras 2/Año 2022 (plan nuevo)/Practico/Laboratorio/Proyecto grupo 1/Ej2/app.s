.globl app
app:
	//---------------- Inicialización GPIO --------------------//

	mov w20, PERIPHERAL_BASE + GPIO_BASE     // Dirección de los GPIO.		
	
	// Configurar GPIOs como input:
	mov X21,#0
	str w21,[x20,GPIO_GPFSEL1] 		// Coloco 0 en Function Select 1 (base + 4)  

    // Configurar GPIO 2 y 3 como output:
	mov X26,#0x240
	str w26,[x20, 0] 			
	
	
	//---------------- Pinta pantalla BEIGE --------------------//
	// X0 contiene la dirección base del framebuffer (NO MODIFICAR)
	mov w3, 0xF7BB    	// 0xF7BB = BEIGE	
	mov x8, 512
	add x10, x0, 0		// X10 contiene la dirección base del framebuffer
loop21:

	mov x10, x0
	mov x2,512         	// Tamaño en Y
loop11:
	mov x1,512         	// Tamaño en X
loop01:
	sturh w3,[x10]	   	// Setear el color del pixel N
	add x10,x10,2	   	// Siguiente pixel
	sub x1,x1,1	   		// Decrementar el contador X
	cbnz x1,loop01	   	// Si no terminó la fila, saltar
	sub x2,x2,1	   		// Decrementar el contador Y
	cbnz x2,loop11	  	// Si no es la última fila, saltar
	



mov w27, 0x000F     // 0x000F = Midnight blue

	mov w26, 0x4
	bl outputOff
	mov w26, 0x8
	bl outputOn
	

	
mov w3, 0xE800  // 0xE800 = Rojo
mov x28, 5      // variable que se utilizara para definir cuantas frutas quedan
mov w27, 0x000F // 0x000F = Midnight blue (color de paredes del laberinto)



//-----------------Dibujo las paredes del laberinto, salida, entrada y frutas con la funcion pincel-------------------//

lineabordeizqarriba:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 3	    //hasta o lim der. en x
	

	mov x5, 0	    //desde o lim arr. en y
	mov x2, 54   	//hasta o lim abaj. en y
	bl pincel
	
	
lineabordeizqabajo:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 3	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 511   	// hasta o lim abaj. en y
	bl pincel
	
	
lineasuperior:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 0	    //desde o lim arr. en y
	mov x2, 3   	// hasta o lim abaj. en y
	bl pincel

lineainferior:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 508	    //desde o lim arr. en y
	mov x2, 511   	// hasta o lim abaj. en y
	bl pincel



lineaderechasuperior:
	mov	x4, 508	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 0	    //desde o lim arr. en y
	mov x2, 411   	// hasta o lim abaj. en y
	bl pincel	



lineaderechainferior:
	mov	x4, 508	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 457	    //desde o lim arr. en y
	mov x2, 511   	// hasta o lim abaj. en y
	bl pincel		
	
	
	
l1V:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 54	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel

l2V:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 54	    //hasta o lim der. en x
	

	mov x5, 202	    //desde o lim arr. en y
	mov x2, 207   	// hasta o lim abaj. en y
	bl pincel

l3V:
	mov	x4, 49	    //desde o lim izq. en x
	mov x7, 105	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 54   	// hasta o lim abaj. en y
	bl pincel

l4V:
	mov	x4, 49	    //desde o lim izq. en x
	mov x7, 105	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 156   	// hasta o lim abaj. en y
	bl pincel

l5V:
	mov	x4, 49	    //desde o lim izq. en x
	mov x7, 156	    //hasta o lim der. en x
	

	mov x5, 253	    //desde o lim arr. en y
	mov x2, 258   	// hasta o lim abaj. en y
	bl pincel	


l6V:
	mov	x4, 49	    //desde o lim izq. en x
	mov x7, 411	    //hasta o lim der. en x
	

	mov x5, 457	    //desde o lim arr. en y
	mov x2, 462   	// hasta o lim abaj. en y
	bl pincel	

l7:
	mov	x4, 49	    //desde o lim izq. en x
	mov x7, 54	    //hasta o lim der. en x
	

	mov x5, 253	    //desde o lim arr. en y
	mov x2, 462   	// hasta o lim abaj. en y
	bl pincel		

l8:
	mov	x4, 100	    //desde o lim izq. en x
	mov x7, 105	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 207   	// hasta o lim abaj. en y
	bl pincel	
	
l9:
	mov	x4, 100	    //desde o lim izq. en x
	mov x7, 207	    //hasta o lim der. en x
	

	mov x5, 202	    //desde o lim arr. en y
	mov x2, 207   	// hasta o lim abaj. en y
	bl pincel	


l10:
	mov	x4, 100	    //desde o lim izq. en x
	mov x7, 105	    //hasta o lim der. en x
	

	mov x5, 304	    //desde o lim arr. en y
	mov x2, 411   	// hasta o lim abaj. en y
	bl pincel	

l11:
	mov	x4, 151	    //desde o lim izq. en x
	mov x7, 156	    //hasta o lim der. en x
	

	mov x5, 202	    //desde o lim arr. en y
	mov x2, 309   	// hasta o lim abaj. en y
	bl pincel		
	
l12:

	mov	x4, 151	    //desde o lim izq. en x
	mov x7, 156	    //hasta o lim der. en x
	

	mov x5, 457	    //desde o lim arr. en y
	mov x2, 511   	// hasta o lim abaj. en y
	bl pincel		
	
l13:
	mov	x4, 151	    //desde o lim izq. en x
	mov x7, 156	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 156   	// hasta o lim abaj. en y
	bl pincel

l14:
	mov	x4, 100	    //desde o lim izq. en x
	mov x7, 309	    //hasta o lim der. en x
	

	mov x5, 406	    //desde o lim arr. en y
	mov x2, 411   	// hasta o lim abaj. en y
	bl pincel		
	
	
l15:
	mov	x4, 100	    //desde o lim izq. en x
	mov x7, 258	    //hasta o lim der. en x
	

	mov x5, 355	    //desde o lim arr. en y
	mov x2, 360   	// hasta o lim abaj. en y
	bl pincel


l16:
	mov	x4, 202	    //desde o lim izq. en x
	mov x7, 207	    //hasta o lim der. en x
	

	mov x5, 253	    //desde o lim arr. en y
	mov x2, 360   	// hasta o lim abaj. en y
	bl pincel	

l17:
	mov	x4, 151	    //desde o lim izq. en x
	mov x7, 258	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 156   	// hasta o lim abaj. en y
	bl pincel	
	
l18:
	mov	x4, 253	    //desde o lim izq. en x
	mov x7, 258	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 258   	// hasta o lim abaj. en y
	bl pincel	


l19:
	mov	x4, 202	    //desde o lim izq. en x
	mov x7, 309	    //hasta o lim der. en x
	

	mov x5, 253	    //desde o lim arr. en y
	mov x2, 258   	// hasta o lim abaj. en y
	bl pincel

l20:
	mov	x4, 202	    //desde o lim izq. en x
	mov x7, 207	    //hasta o lim der. en x
	

	mov x5, 0	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel	

l21:
	mov	x4, 202	    //desde o lim izq. en x
	mov x7, 309	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel

l22:
	mov	x4, 304	    //desde o lim izq. en x
	mov x7, 309	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 258   	// hasta o lim abaj. en y
	bl pincel

l23:
	mov	x4, 253	    //desde o lim izq. en x
	mov x7, 462	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 54   	// hasta o lim abaj. en y
	bl pincel

l24:
	mov	x4, 355	    //desde o lim izq. en x
	mov x7, 360	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel		

l25:
	mov	x4, 406	    //desde o lim izq. en x
	mov x7, 411	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 360   	// hasta o lim abaj. en y
	bl pincel

l26:
	mov	x4, 355	    //desde o lim izq. en x
	mov x7, 360	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 309   	// hasta o lim abaj. en y
	bl pincel		
	
l27:
	mov	x4, 253	    //desde o lim izq. en x
	mov x7, 360	    //hasta o lim der. en x
	

	mov x5, 304	    //desde o lim arr. en y
	mov x2, 309   	// hasta o lim abaj. en y
	bl pincel	

l28:
	mov	x4, 304	    //desde o lim izq. en x
	mov x7, 309	    //hasta o lim der. en x
	

	mov x5, 304	    //desde o lim arr. en y
	mov x2, 411   	// hasta o lim abaj. en y
	bl pincel		


l29:
	mov	x4, 355	    //desde o lim izq. en x
	mov x7, 411	    //hasta o lim der. en x
	

	mov x5, 355	    //desde o lim arr. en y
	mov x2, 360   	// hasta o lim abaj. en y
	bl pincel	
	
l30:
	mov	x4, 355	    //desde o lim izq. en x
	mov x7, 360	    //hasta o lim der. en x
	

	mov x5, 355	    //desde o lim arr. en y
	mov x2, 462   	// hasta o lim abaj. en y
	bl pincel	
	
l31:
	mov	x4, 457	    //desde o lim izq. en x
	mov x7, 462	    //hasta o lim der. en x
	

	mov x5, 49	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel		
	
l32:
	mov	x4, 457	    //desde o lim izq. en x
	mov x7, 462	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 360   	// hasta o lim abaj. en y
	bl pincel	

l33:
	mov	x4, 457	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 151	    //desde o lim arr. en y
	mov x2, 156   	// hasta o lim abaj. en y
	bl pincel

l34:
	mov	x4, 355	    //desde o lim izq. en x
	mov x7, 411	    //hasta o lim der. en x
	

	mov x5, 100	    //desde o lim arr. en y
	mov x2, 105   	// hasta o lim abaj. en y
	bl pincel	

l35:
	mov	x4, 406	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 406	    //desde o lim arr. en y
	mov x2, 411   	// hasta o lim abaj. en y
	bl pincel

l36:
	mov	x4, 457	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 457	    //desde o lim arr. en y
	mov x2, 462   	// hasta o lim abaj. en y
	bl pincel	


salida:
	mov	x4, 0	    //desde o lim izq. en x
	mov x7, 25	    //hasta o lim der. en x
	

	mov x5, 55	    //desde o lim arr. en y
	mov x2, 99   	// hasta o lim abaj. en y
	
	
	mov w27, 0xE800 //cambio el color a rojo para el inicio
	
	bl pincel	
	
	
frutas:
	
f1:
	
	
	mov	x4, 230	    //desde o lim izq. en x
	mov x7, 235	    //hasta o lim der. en x
	

	mov x5, 25	    //desde o lim arr. en y
	mov x2, 30   	// hasta o lim abaj. en y
	
	mov w6, 0xF800
	mov w27, w6
	bl pincel	
	
		
f2:
	
	
	mov	x4, 130	    //desde o lim izq. en x
	mov x7, 135	    //hasta o lim der. en x
	

	mov x5, 490	    //desde o lim arr. en y
	mov x2, 495   	// hasta o lim abaj. en y
	

	mov w6, 0xF801
	mov w27, w6
	bl pincel	
	
	
f3:
	
	
	mov	x4, 275	    //desde o lim izq. en x
	mov x7, 280	    //hasta o lim der. en x
	

	mov x5, 225	    //desde o lim arr. en y
	mov x2, 230   	// hasta o lim abaj. en y
	
	

	mov w6, 0xF802
	mov w27, w6
	bl pincel
	
f4:
	mov x4, 485
	mov x7, 490
	
	mov x5, 485
	mov x2, 490
	
	mov w6, 0xF803 
	mov w27, w6
	bl pincel	


f5:
	
	
	mov	x4, 130	    //desde o lim izq. en x
	mov x7, 135	    //hasta o lim der. en x
	

	mov x5, 380	    //desde o lim arr. en y
	mov x2, 385   	// hasta o lim abaj. en y
	
	

	mov w6, 0xF804 
	mov w27, w6
	bl pincel	
	
	
	
	
	
	
	
	

llegada:
	mov	x4, 486	    //desde o lim izq. en x
	mov x7, 511	    //hasta o lim der. en x
	

	mov x5, 412	    //desde o lim arr. en y
	mov x2, 456   	// hasta o lim abaj. en y
	
	
	mov w27, 0x682  //cambio el color a verde para el final
	
	bl pincel		
	b personaje
	
	
	
	


	
//-------------funcion pincel: dibuja rectangulos a partir de coordenadas en x e y----------------//
	
pincel:	
	mov x1, x7
pincel0:	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	cmp x1, x4
	beq pincely
	sub x1,x1,1
	b pincel0
pincely:	
	cmp x2, x5
	beq volver
	sub x2,x2,1	   		
	b pincel
volver:
	br x30
	
	
	
	
	
	
//---------------------------------------------PERSONAJE--------------------------------------------------------------//	

	
personaje:                //setea posicion inicial del personaje
	mov x7, 43
	mov x12, 95


personaje1:


	cbnz x28, p    //verifica si quedan frutas, en tal caso sigue sin cambiar los leds
	mov w26, 0x4
	bl outputOn    //En caso de haber comido todas las frutas prendo el led verde
	mov w26, 0x8
	bl outputOff   //apago led rojo



p:

	mov x1, x7    //seteo la posicion en x donde se dibujara el personaje
	mov x2, x12   	//sete la posicion en y donde se dibujara el personaje


//-----Dibujo el personaje a partir de la posicion indicada--------//
li1:
mov w27, 0x0000     //cambio al color que necesito (negro)
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]  //pinto en la posicion indicada utilizando la formula
sub x1, x1, 1         //voy modificando las variables en x e y para ir pintando pixel por pixel
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 3
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
li2:	
add x1, x1, 1
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 3
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li3:	
add x1, x1, 2
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x00FF
mov x11, 0
a8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne a8
mov w27, 0x0000
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li4:
sub x2, x2, 1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov w27, 0x00FF
mov x11, 0
b8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne b8
add x1, x1, 1
mov w27, 0x0000
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
li5:	
sub x1, x1, 1
sub x2, x2, 1
mov w27, 0xE5A1	 //amarillo
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x00FF
mov x11, 0
c8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne c8
	
mov w27, 0xE5A1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
li6:	
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x00FF
mov x11, 0
d8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 6 	
	bne d8
add	x1, x1, 1
mov w27, 0xE5A1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
li7:
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x00FF
mov x11, 0
z8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 6 	
	bne z8
sub	x1, x1, 1
mov w27, 0xE5A1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li8:
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
mov w27, 0x00FF
mov x11, 0
e8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne e8
add x1, x1, 1
mov w27, 0xE5A1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

li9:
sub x2, x2, 1
mov w27, 0x00FF
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xE5A1
mov x11, 0
f8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne f8
mov w27, 0x00FF
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li10:	
mov w27, 0xE5A1
sub x2, x2, 1
mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
g8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 9 	
	bne g8
	
li11:
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x0000
mov x11, 0
h8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 4 	
	bne h8
sub x1, x1, 1	
mov w27, 0xE5A1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	
li12:

sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x0000
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0	
mov w27, 0xE5A1	
y8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 4 	
	bne y8
add x1, x1, 1
mov w27, 0x0000
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
add x1, x1, 1
mov w27, 0xE5A1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	
li13:
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]		
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

mov w27, 0x4B4B //gris
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
mov w27, 0xE5A1	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

li14:
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

mov w27, 0x4B4B
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xFFFF
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x4B4B
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xE5A1
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li15:
sub x2, x2, 1
mov w27, 0x0000
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x4B4B
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xFFFF
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x0000
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
mov w27, 0xFFFF
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov w27, 0x4B4B
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov w27, 0x0000
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li16:
	
	sub x2, x2, 1
mov w27, 0x0000
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x4B4B
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xFFFF
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x0000
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
mov w27, 0xFFFF
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov w27, 0x4B4B
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov w27, 0x0000
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
li17:
mov w27, 0xE5A1
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x4B4B
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xFFFF
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0x4B4B
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov w27, 0xE5A1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

li18:
sub x2, x2, 1
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
mov w27, 0x4B4B
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
mov w27, 0xE5A1
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]		

li19:
sub x2, x2, 1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	
//--delay--//
mov x13, 0xF000
delay1:
	sub x13, x13, 1
	cbnz x13, delay1
//--fin_delay--//	


	bl inputRead        //una vez dibujado el personaje consulto si alguno de los botones esta presionado
	cbnz x22, abajo     //consulto por boton abajo
	cbnz x23, izquierda  //consulto por boton izquierda
	cbnz x24, derecha    //consulto por boton derecha
	cbnz x25, arriba	//consulto por boton arriba



b personaje1	//si ningun boton esta presionado vuelvo a dibujar el personaje en la misma posicion infinitamente





abajo: //si se toca el boton comienzo por verificar que no exista una pared
       //posicionando x e y en distintas posiciones alrededor del personaje

	add x12, x12, 1    //sumo 1 en y a partir del inicio de donde se dibuja el personaje
	add x7, x7, 1      //sumo 1 en x a partir del inicio de donde se dibuja el personaje
	mov x2, x12        // guardo ambos resultados en mis variables x e y de la formula
	mov x1, x7
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]  //pregunto por el color del pixel en la posicion buscada
	
	sub x7, x7, 1    //devuelvo los registros anteriormente cambiados a su valor original
	sub x12, x12, 1  //devuelvo los registros anteriormente cambiados a su valor original
	cmp w27, 0x000F  //pregunto si el color del pixel es el de la pared
	beq personaje1   // en tal caso vuelvo a dibujar el personaje sin cambiar su posicion
	cmp w27, w3      //pregunto si el color del pixel es el del inicio
	beq personaje1   // en tal caso vuelvo a dibujar el personaje sin cambiar su posicion
	
	mov w6, 0xF800   //0xF800 = Rojo (color fruta 1) guardo en w6 el color de la fruta
	cmp w27, w6      //pregunto si el color del pixel es el de la fruta
	beq ff1          //en caso positivo me voy a la funcion de la fruta 1
	mov w6, 0xF801   //0xF801 = Rojo (color fruta 2) guardo en w6 el color de la fruta
	cmp w27, w6	     //pregunto si el color del pixel es el de la fruta
	beq ff2          //en caso positivo me voy a la funcion de la fruta 2
	mov w6, 0xF802   //realizo esto con cada color de cada fruta
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	                   //si lo anterior no detecto nada repito con otras posiciones de x e y para abarcar todo el personaje
	add x12, x12, 1  
	sub x7, x7, 2
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	sub x12, x12, 1
	add x7, x7, 2
	
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
		
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	
	add x12, x12, 1
	sub x7, x7, 5
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	sub x12, x12, 1
	add x7, x7, 5
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	
	add x12, x12, 1
	sub x7, x7, 9
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	sub x12, x12, 1
	add x7, x7, 9
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	

avanzaabajo:                //si no se logro detectar nada el personaje puede avanzar
	bl borrarpersonaje      //llamo a la funcion borrarpersonaje para eliminar el dibujo del personaje en la pos. actual
	add x12, x12, 1         //sumo 1 en el y del personaje
	b personaje1            //vuelvo a la funcion personaje
	
	
	
	
	
	
izquierda:   			//si se toca el boton comienzo por verificar que no exista una pared
						//posicionando x e y en distintas posiciones alrededor del personaje
						//Se realiza el mismo proceso que el explicado en la funcion abajo

    sub x7, x7, 10
	mov x1, x7
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	add x7, x7, 10
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3     //w3 = color del inicio
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
//	
	sub x7, x7, 10
	sub x12, x12, 5
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	add x12, x12, 5
	add x7, x7, 10
	
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	sub x12, x12, 10
	sub x7, x7, 10
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 10
	add x7, x7, 10
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	sub x12, x12, 15
	sub x7, x7, 10
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 15
	add x7, x7, 10
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	
	sub x12, x12, 19
	sub x7, x7, 10
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 19
	add x7, x7, 10
	cmp w27, 0x000F
	beq personaje1
	cmp w27, w3
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5


//


avanzainquierda: 
	bl borrarpersonaje  //llamo a la funcion y borro el personaje en la posicion actual
	sub x7, x7, 1       //resto 1 a la posicion en x del personaje
	b personaje1        //vuelvo a la funcion personaje1




derecha:                  //si se toca el boton comienzo por verificar que no exista una pared
                          //posicionando x e y en distintas posiciones alrededor del personaje
	                       //Se realiza el mismo proceso que el explicado en la funcion abajo
	add x7, x7, 3
	mov x1, x7
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	sub x7, x7, 3
	cmp w27, 0x000F
	beq personaje1
	cmp w27, 0x682   //compruebo si el pixel es del color del final
	beq final        //en caso positivo voy a la funcion final
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
//	
	add x7, x7, 3
	sub x12, x12, 5
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	add x12, x12, 5
	sub x7, x7, 3
	
	cmp w27, 0x000F
	beq personaje1
	cmp w27, 0x682
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	sub x12, x12, 10
	add x7, x7, 3
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 10
	sub x7, x7, 3
	cmp w27, 0x000F
	beq personaje1
	cmp w27, 0x682
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	sub x12, x12, 15
	add x7, x7, 3
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 15
	sub x7, x7, 3
	cmp w27, 0x000F
	beq personaje1
	cmp w27, 0x682
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
//	
	
	sub x12, x12, 19
	add x7, x7, 3
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 19
	sub x7, x7, 3
	cmp w27, 0x000F
	beq personaje1
	cmp w27, 0x682
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5




avanzaderecha:
	bl borrarpersonaje      //llamo a la funcion para borrar el personaje de la posicion actual
	add x7 , x7 , 1			//sumo 1 en la posicion en x del personaje
	b personaje1			//vuelvo a la funcion personaje1




arriba:   					//si se toca el boton comienzo por verificar que no exista una pared
							//posicionando x e y en distintas posiciones alrededor del personaje
							//Se realiza el mismo proceso que el explicado en la funcion abajo


	sub x12, x12, 19
	add x7, x7, 1
	mov x2, x12
	mov x1, x7
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	sub x7, x7, 1
	add x12, x12, 19
	cmp w27, 0x000F
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	sub x12, x12, 19
	sub x7, x7, 2
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	add x12, x12, 19
	add x7, x7, 2
	
	cmp w27, 0x000F
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	
	sub x12, x12, 19
	sub x7, x7, 5
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 19
	add x7, x7, 5
	cmp w27, 0x000F
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5
	
	
	sub x12, x12, 19
	sub x7, x7, 9
	mov x1, x7
	mov x2, x12
	
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	ldurh w27,[x10]
	
	
	add x12, x12, 19
	add x7, x7, 9
	cmp w27, 0x000F
	beq personaje1
	mov w6, 0xF800
	cmp w27, w6
	beq ff1
	mov w6, 0xF801
	cmp w27, w6
	beq ff2
	mov w6, 0xF802
	cmp w27, w6
	beq ff3
	mov w6, 0xF803
	cmp w27, w6
	beq ff4
	mov w6, 0xF804 
	cmp w27, w6
	beq ff5




avanzaarriba:
	bl borrarpersonaje       //llamo a la funcion para borrar el personaje de la posicion actual
	sub x12, x12, 1			//resto 1 a la posicion en y del personaje
	b personaje1			//vuelvo a la funcion personaje1




ff1:                          //la funcion de la fruta borra la fruta y resta 1 al numero de frutas
	sub x28, x28, 1
	
	mov x9, x7               //guardo la posicion que tenia de x7, antes de utilizarla para borrar la fruta
	
	mov	x4, 230	    //desde o lim izq. en x
	mov x7, 235	    //hasta o lim der. en x
	

	mov x5, 25	    //desde o lim arr. en y
	mov x2, 30   	// hasta o lim abaj. en y
	mov w27, 0xF7BB  //pongo el color del fondo para que se cambien los pixeles de la fruta al color del fondo
	bl pincel	
	mov x7, x9       //devuelvo el registro x7 al valor que tenia antes de ser utilizado para borrar la fruta
	bl borrarpersonaje
	b personaje1
	
ff2:					//se sigue el mismo proceso que el documnetado para ff1
	sub x28, x28, 1
	mov x9, x7
	
	mov	x4, 130	    //desde o lim izq. en x
	mov x7, 135	    //hasta o lim der. en x
	

	mov x5, 490	    //desde o lim arr. en y
	mov x2, 495   	// hasta o lim abaj. en y
	mov w27, 0xF7BB
	bl pincel	
	mov x7, x9
	bl borrarpersonaje
	b personaje1
	
ff3:						//se sigue el mismo proceso que el documnetado para ff1
	sub x28, x28, 1
	mov x9, x7
	
	mov	x4, 275	    //desde o lim izq. en x
	mov x7, 280	    //hasta o lim der. en x
	

	mov x5, 225	    //desde o lim arr. en y
	mov x2, 230   	// hasta o lim abaj. en y
	mov w27, 0xF7BB
	bl pincel
	mov x7, x9
	bl borrarpersonaje
	b personaje1

ff4:					//se sigue el mismo proceso que el documnetado para ff1
	sub x28, x28, 1
	mov x9, x7
	
	mov	x4, 485	    //desde o lim izq. en x
	mov x7, 490	    //hasta o lim der. en x
	

	mov x5, 485	    //desde o lim arr. en y
	mov x2, 490  	// hasta o lim abaj. en y
	mov w27, 0xF7BB
	bl pincel	
	mov x7, x9
	bl borrarpersonaje
	b personaje1

ff5:					//se sigue el mismo proceso que el documnetado para ff1
	sub x28, x28, 1
	mov x9, x7
	
	mov	x4, 130	    //desde o lim izq. en x
	mov x7, 135	    //hasta o lim der. en x
	

	mov x5, 380	    //desde o lim arr. en y
	mov x2, 385   	// hasta o lim abaj. en y
	mov w27, 0xF7BB
	bl pincel	
	mov x7, x9
	bl borrarpersonaje
	b personaje1




 //-------------------------------BORRARPERSONAJE--------------------------------------------//
 
 borrarpersonaje:   //esta funcion dibuja el personaje segun las coordenadas indicadas pero con el color del fondo

	mov x1, x7    //hasta o lim der. en x
	mov x2, x12   	// hasta o lim abaj. en y
	mov w27, 0xF7BB  //0xF7BB = Beige (color del fondo)



	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 3
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
	
add x1, x1, 1
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 3
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 2
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
aa8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne aa8
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x2, x2, 1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov x11, 0
bb8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne bb8
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
cc8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne cc8
	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	

sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
dd8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 6 	
	bne dd8
add	x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
zz8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 6 	
	bne zz8
sub	x1, x1, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	

mov x11, 0
ee8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne ee8
add x1, x1, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	


sub x2, x2, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov x11, 0
ff8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 8 	
	bne ff8

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x2, x2, 1
mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0
gg8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 9 	
	bne gg8
	

sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

mov x11, 0
hh8:
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 4 	
	bne hh8
sub x1, x1, 1	

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	


sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
mov x11, 0	
yy8:
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	add x11, x11, 1
	cmp x11, 4 	
	bne yy8
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	
add x1, x1, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	

sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]		
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	


sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	


sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x2, x2, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


	
	sub x2, x2, 1

	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
	

sub x2, x2, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]

sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]


sub x2, x2, 1
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	

add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
add x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]		


sub x2, x2, 1
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
sub x1, x1, 1
	mul x26, x2, x8
	add x10, x26, x1
	add x10, x10, x10
	add x10, x0, x10
	sturh w27,[x10]	
	
	br x30
	


final:      //la funcion final consulta si el contador de frutas llego a 0 en caso negativo vuelve a la funcion personaje1
			//en caso positivo la funcion se realiza en bucle infinito realizando un juego de luces
	cbnz x28, personaje1   //pregunta si el contador de frutas es 0
	
		//delay//
	mov x13, 0xFFFF
	mov x14, 0x000A
	delay2:
	sub x13, x13, 1
	cbnz x13, delay2
	mov x13, 0xFFFF
	sub x14, x14, 1
	cbnz x14, delay2
	//fin_delay//
	
	mov w26, 0x4
	bl outputOff  //apago el led verde
	mov w26, 0x8
	bl outputOn  //enciendo led rojo
	
	//delay//
	mov x13, 0xFFFF
	mov x14, 0x000A
	delay3:
	sub x13, x13, 1
	cbnz x13, delay3
	mov x13, 0xFFFF
	sub x14, x14, 1
	cbnz x14, delay3
	//fin_delay//
	
	mov w26, 0x4
	bl outputOn   //enciendo led verde
	mov w26, 0x8
	bl outputOff  //apago led rojo
	
b final	    //vuelvo a la funcion final


	