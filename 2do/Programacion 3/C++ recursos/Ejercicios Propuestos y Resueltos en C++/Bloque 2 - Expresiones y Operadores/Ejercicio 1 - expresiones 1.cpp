//1. Escribe la siguiente expresi�n como expresi�n en C++: (a/b) + 1

#include<iostream>

using namespace std;

int main(){
	float a,b,resultado=0;
	
	cout<<"Digite el valor de a: "; 
	cin>>a;
	cout<<"Digite el valor de b: ";
	cin>>b;
	
	resultado = (a/b) + 1;
	
	cout.precision(2);//recorta los n�meros despues de la coma decimal a 2
	
	cout<<"El resultado es: "<<resultado;	
	
	return 0;
}
