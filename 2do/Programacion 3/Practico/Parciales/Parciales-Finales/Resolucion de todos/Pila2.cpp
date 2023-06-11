/* [Ejercicio 2]
Escriba una función que indique si dos pilas son iguales. Se entiende que dos pilas son
iguales cuando sus elementos son idénticos y aparecen en el mismo orden.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    Pila<int> p1, p2;        //Declaramos dos pilas.
    bool igual = true;       //Variable bool que indica si las pilas son iguales o no.

    for (int i = 0; i < 5; i++) {    //Agregamos elementos en las pilas.
        p1.push(i+5);
        p2.push(i*2);
    }

    for (int j = 0; j < 5; j++) {    //Recorremos las pilas.
        if(p1.pop() != p2.pop()){    //Comparamos los valores del tope de cada una. En el caso de en algun valor sean
            igual = false;           //distintos, la variable bool la ponemos en false y directamente salimos del ciclo.
            break;
        }
    }

    if(!igual){
        cout<<"Las pilas no son iguales";
    }else{
        cout<<"Las pilas son iguales";
    }

    return 0;
}