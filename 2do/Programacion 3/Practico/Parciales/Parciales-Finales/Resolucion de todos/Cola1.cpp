/* [Ejercicio 1]
Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar
si son iguales. Nota: los elementos constitutivos de las colas son caracteres.
*/


#include "./Estructuras/Cola.h"
#include <iostream>
using namespace std;

int main() {
    Cola<char> c1, c2;
    char newLeter1 = ' ';
    char newLeter2 = ' ';
    bool igual = true;


    cout<<"Ingrese cola 1: ";
    while( newLeter1 != '.'){    //ponemos un punto para salir
        cin>>newLeter1;
        c1.encolar(newLeter1);
    }
    c1.desencolar();

    cout<<endl;
    cout<<"Ingrese cola 2: ";
    while( newLeter2 != '.'){    //ponemos un punto para salir
        cin>>newLeter2;
        c2.encolar(newLeter2);
    }

    c2.desencolar();

    cout<<endl;
    for (int j = 0; j < 3; j++) {
        if(c1.desencolar()!=c2.desencolar()){
            igual = false;      //1 es lo mismo que true
            break;
        }
    }

    if(!igual){
        cout<<"Las colas no son iguales";
    }else{
        cout<<"Las colas son iguales";
    }

    return 0;
}