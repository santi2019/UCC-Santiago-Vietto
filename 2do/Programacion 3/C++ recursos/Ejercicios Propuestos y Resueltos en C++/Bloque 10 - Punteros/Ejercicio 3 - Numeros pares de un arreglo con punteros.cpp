/*Ejercicio 3: Rellenar un array de 10 n�meros, posteriormente utilizando punteros 
indicar cuales son n�meros pares y su posicion en memoria. */

#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numeros[10], *dir_numeros;
	
	for(int i=0;i<10;i++){//Pidiendo los n�meros al usuario
		cout<<i+1<<". Digite un numero: ";
		cin>>numeros[i];
	}
	
	dir_numeros = numeros; //indicar al puntero que inicie en a[0]
	
	for(int i=0;i<10;i++){
		if(*dir_numeros%2==0){//Comprobar n�meros pares
			cout<<"Numero par: "<<*dir_numeros<<endl;
			cout<<"Posicion: "<<dir_numeros<<endl;
		}
		dir_numeros++;
	}
	
	
	getch();
	return 0;
}
