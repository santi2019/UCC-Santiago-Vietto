/* [Ejercicio 8]:
Escribir un método de la clase lista int tamanio(Nodo* n) que, de manera
recursiva, cuente cuantos nodos posee la lista enlazada.
"RESUELTO EN LISTA.H"
*/

#include "Estructuras/Lista.h"
#include <iostream>
using namespace std;

/*En public:
int tamanio() {
  tamanio(inicio);
}
*/


/*En cpp:
template<class T> int Lista<T>::tamanio(Nodo<T> *n){
    if(n == nullptr){
        return 0;
    }else{
        return 1 + tamanio(n->getSiguiente());
    }
}
*/

int main(){
    Lista<int> l1;

    for(int i=0;i<100;i++){
        l1.insertarUltimo(i);
    }

    cout<<"La lista tiene: "<< l1.tamanio() <<" nodos";
}