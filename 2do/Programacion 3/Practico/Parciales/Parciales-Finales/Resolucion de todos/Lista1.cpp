/* [Ejercicio 1]
Implementar la función fnInvierte(lista). Esta función invertirá el orden original de los
elementos en la lista, de tal forma que el último elemento será ahora el primero, el penúltimo
será el segundo, y así hasta que el primero sea el último. Considere que la lista no está
vacía y que no se construirá una nueva, solo se invertirá el orden de los elementos de la
lista original.
*/


#include "./Estructuras/Lista.h"
#include <iostream>
using namespace std;

template <class T> void fnInvierte(Lista<T> *lis){
    T aux, aux2;                     //Declaramos dos variables auxiliares.
    int size = lis->getTamanio();    //Traemos el tamaño de la lista original.

    for(int i=0; i<size/2; i++){            //Ciclo que corre hasta la mitad del tamaño, e iteramos.
        aux = lis->getDato(i);         //Aux va a ser la variable del inicio.
        aux2 = lis->getDato(size-1-i); //Aux2 es el valor en el final de la lista menos el punto de iteracion donde estamos parados.
        lis->reemplazar(i,aux2);        //Reemplazamos en la posicion inicial el valor de aux2.
        lis->reemplazar(size-1-i,aux);  //Reemplazamos en la ultima poscion, no nullptr, el valor de aux.
    }
}


int main() {
    Lista<int> list1;                   //Declaramos una lista.

    for(int i=0;i<10;i++){             //Rellenamos la lista con valores.
        list1.insertarUltimo(i);
    }

    cout<<"Lista original: "<<endl;     //Imprimimos la lista.
    list1.print();
    cout<<endl;

    cout<<"Tamanio de la lista: "<<list1.getTamanio()<<endl;    //Obtenemos el tamaño de la lista.
    cout<<endl;

    fnInvierte(&list1);              //Pasamos la direccion de memoria (referencia) de la lista.

    cout<<"Lista invertida: "<<endl;    //Imprimimos la lista invertida.
    list1.print();

    return 0;
}





