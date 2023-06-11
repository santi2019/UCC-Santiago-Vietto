/* [Ejercicio 4]
Crear una función que dada dos listas enlazadas, pasadas como parámetro, devuelva
una lista enlazada que es la unión de las otras dos.
*/


#include "./Estructuras/Lista.h"
#include <iostream>
using namespace std;

template <class T> Lista<T> *unir(const Lista<T> &lisA, const Lista<T> &lisB) {
    Lista<T> *auxA = new Lista<T>(lisA);  //Le pasamos al constructor por copia la referencia de lisA (dir. de memoria).
    Lista<T> *auxB = new Lista<T>(lisB);  //Le pasamos al constructor por copia la referencia de lisB (dir. de memoria).
    int size = auxB->getTamanio();        //Tenemos el tamaño de auxB.

    for (int i = 0; i < size; i++) {      //Recorremos el tamaño de la lista B
        auxA->insertarUltimo(auxB->getDato(i));  //De forma iterativa ingresamos siempre al ultimo los datos
    }                                                      //de la lista B en la lista A hasta que lleguemos al final.

    delete auxB;      //Liberamos memoria.

    return auxA;
}


int main() {
    Lista<int> *listA = new Lista<int>();
    Lista<int> *listB = new Lista<int>();

    for(int i = 0; i < 20; i++) {
        listA->insertarPrimero(i);
        listB->insertarPrimero(i*3);
    }

    cout<<"Lista A: "<<endl;
    listA->print();
    cout<<endl;

    cout<<"Lista B: "<<endl;
    listB->print();
    cout<<endl;

    Lista<int> *listC = unir(*listA, *listB);

    cout<<"Lista C:"<<endl;
    listC->print();

    return 0;
}

