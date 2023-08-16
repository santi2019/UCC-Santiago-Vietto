//--------DEFINICIÓN DE FUNCIONES-----------//
    .global inputRead    
	//DESCRIPCION: Lee el boton en el GPIO17. 
//------FIN DEFINICION DE FUNCIONES-------//

inputRead: 	
	ldr w22, [x20, GPIO_GPLEV0] 	// Leo el registro GPIO Pin Level 0 y lo guardo en X22
	and X22,X22,#0x20000	// Limpio el bit 17 (estado del GPIO17)
		
    br x30 		//Vuelvo a la instruccion link
