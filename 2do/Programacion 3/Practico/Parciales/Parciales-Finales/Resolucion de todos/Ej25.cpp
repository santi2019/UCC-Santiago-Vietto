/*Consigna: Implementar un programa que dada una lista de valores enteros, encuentre todos los
números múltiplos de 3 y los reacomode al final de la lista en el orden inverso en el cual
fueron encontrados.*/

#include <iostream>
#include "Lista/Lista.h"
#include "Pila/Pila.h"
using namespace std;



int main(){
    Lista<int> l;
    Pila<int> pl;

    l.insertarUltimo(21);
    l.insertarUltimo(5);
    l.insertarUltimo(4);
    l.insertarUltimo(6);
    l.insertarUltimo(33);
    l.insertarUltimo(8);
    l.insertarUltimo(9);

    cout << "Lista antes de reordenar: ";
    l.print();

    int size = l.getTamanio();

    for(int i=0; i < l.getTamanio(); i++){
         if(l.getDato(i) % 3 == 0 ){
            pl.push(l.getDato(i));
            l.remover(i);
        }
    }

    while (!pl.esVacia()){
        l.insertarUltimo(pl.pop());
    }

   // l.multiplosAlUltimo(3);

    cout << "Lista con multiplos de 3 al final e invertidos: ";
    l.print();

    return 0;
}