/* [Ejercicio 19]:
Se pretende realizar una función que, reciba por referencia una cola e
invierta todo su contenido:
    Void invertir(cola <int>&col);
*/

#include <iostream>
#include "Estructuras/Cola.h"
#include "Estructuras/Pila.h"
using namespace std;

void colaInvertida(Cola<int>& col){
    Pila<int> pl;

    while (!col.esVacia()) {
        pl.push(col.peek());
        col.desencolar();
    }

    while (!pl.esVacia()) {
        col.encolar(pl.peek());
        pl.pop();
    }

}

int main(){

    Cola<int> col;
    col.encolar(2);
    col.encolar(4);
    col.encolar(6);
    col.encolar(8);

    cout<<"Cola original: "<<endl;
    col.toString();
    cout<<endl;

    colaInvertida(col);

    cout<<"Cola invertida: "<<endl;
    col.toString();
    cout<<endl;

    return 0;
}
