//--------DEFINICIÓN DE FUNCIONES-----------//
    .global inputRead    
	//DESCRIPCION: Lee el boton en el GPIO17. 
//------FIN DEFINICION DE FUNCIONES-------//

inputRead: 	
	ldr w21, [x20, GPIO_GPLEV0] 	// Leo el registro GPIO Pin Level 0 y lo guardo en X22
	and X22, X21,#0x20000	// Limpio el bit 17 (estado del GPIO17)
	and x23, x21, #0x40000  // Limpio el bit 18 (estado del GPIO18)
	and x24, x21, #0x8000   // Limpio el bit 15 (estado del GPIO15)
	and x25, x21, #0x4000   // Limpio el bit 14 (estado del GPIO14)
	br x30 		//Vuelvo a la instruccion link
	

outputOff:
 	str w26, [x20, 0x1c]
 	br x30

outputOn:
	str w26, [x20, 0x28]
	br x30		
	
	
	
	
	
