.globl app
app:
	//---------------- Inicialización GPIO --------------------

	mov w20, PERIPHERAL_BASE + GPIO_BASE     // Dirección de los GPIO.		
	
	// Configurar todos los GPIO como input:
	mov X21,#0
	str w21,[x20,GPIO_GPFSEL1] 		// Coloco 0 en Function Select 1 (base + 4)   	
	
	//---------------- Main code --------------------
	// X0 contiene la dirección base del framebuffer (NO MODIFICAR)
	mov w12, 0x20  //para trabajar con led verde
	mov w13, 0x800  //para trabajar con led rojo
	mov w14, 0x1    //para trabajar con led azul
	mov x20, 0
	mov w3, 0xF800    	// 0xF800 = ROJO	
	add x10, x0, 0		// X10 contiene la dirección base del framebuffer
loop2:
	mov x2, 512         	// Tamaño en Y
loop1:
	mov x1, 512     	// Tamaño en X
	movz w3, 0xF800    	// 0xF800 = ROJO
sec1:
	sturh w3,[x10]	   	// Pinto en la posicion x10
	add x10,x10,2	 	// sumo 2 a x10 para pasar al siguiente pixel
	sturh w3,[x10]	   //vuelvo a pintar en la posicion siguiente
	add x10,x10,2	   //paso al siguiente pixel
	add w3, w3, w12    //aumento el color verde
	sub x1,x1,2		// Decrementar el contador X
	cmp x1, 386     //comparo si termino la primer secuencia de colores
	beq sec2        //si no termino repito
	b sec1          //si termino paso a la siguiente secuencia
sec2:
	sturh w3,[x10]	   	//sigo la secuencia decrementando el color rojo
	add x10,x10,2	   	
		sturh w3,[x10]	   	
	add x10,x10,2	   	
	sub x1,x1,2	   		
	sub w3, w3, w13
	cmp x1, 324
	beq sec3
	b sec2

	
sec3:
	sturh w3,[x10]	   	//sigo secuencia incrementando el color azul
	add x10,x10,2	  
		sturh w3,[x10]	   	
	add x10,x10,2	   
	sub x1,x1,2	   		
	add w3, w3, w14
	cmp x1, 262
	beq sec4
    b sec3
	
sec4:
	sturh w3,[x10]	   	//sigo secuencia decrementando el color verde
	add x10,x10,2	   	
		sturh w3,[x10]	   	
	add x10,x10,2	   	
	sub x1,x1,2	   		
	sub w3, w3, w12
	cmp x1, 136
	beq sec5
    b sec4
	
sec5:
	sturh w3,[x10]	   	//Sigo secuencia incrementando el color rojo
	add x10,x10,2	   	
		sturh w3,[x10]	 
	add x10,x10,2	   	
	sub x1,x1,2	   		
	add w3, w3, w13
	cmp x1, 74
	beq sec6
	b sec5
	
sec6:
	sturh w3,[x10]	   	//sigo secuencia decrementando el color azul
	add x10,x10,2	   
		sturh w3,[x10]	
	add x10,x10,2	   
	sub x1,x1,2	   		
	sub w3, w3, w14
	cmp x1, 12
	beq final
	b sec6
	
final:                      //relleno los ultimos pixeles que sobran a la derecha con color rojo
		sturh w3,[x10]	   	
	add x10,x10,2	   	
		sturh w3,[x10]	   	
	add x10,x10,2	   	
	sub x1,x1,2	   		
	cbnz x1, final
	sub x2,x2,1	   		
	cbnz x2, loop1	  	
	b infloop	         //si termino me voy al loop infinito
	

infloop:
b infloop
	