/* [Ejercicio 1]
Escriba un programa que introduzca una palabra y utilice una pila
para imprimir la misma palabra invertida.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main(){

    char newLeter = ' ';    //Inicializamos el caracter a ingresar a la pila (no es necesario el ' ').
    char invertedWord;      //Variable para almacenar las letras invertidas.

    Pila<char> p1;          //Declaramos una pila de tipo char.

    cout<<"Ingrese la palabra que desee invertir: ";
    while( newLeter != '.'){                //Ciclo para ingresar letras. Ponemos un punto para salir.
        cin>>newLeter;
        p1.push(newLeter);
    }

    p1.pop();                               //Sacamos el ultimo punto que agregamos.

    cout<<endl;
    cout<<"Palabra invertida: ";
    while(!p1.esVacia()){                   //Mientras la pila no este vacia.
        invertedWord = p1.pop();            //Guardamos las letras que sacamos desde el tope de la pila y las mostramos.
        cout<<invertedWord;
    }
    cout<<endl;
    return 0;
}