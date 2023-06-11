/* [Ejercicio 9]:
Se pretende realizar un método en la lista enlazada que, mediante un algoritmo,
calcule la suma de los enteros almacenados donde el valor sea superior a un valor
umbral que se pasará como parámetro al método.
*/

#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;

class ListaSuma : public Lista<int> {
public:
    int sumaDesde(int umbral){
        Nodo<int> *aux = inicio;
        int sum;

        while(aux != nullptr){
            if(aux->getDato() > umbral){
                sum = sum + aux->getDato();
            }
            aux = aux->getSiguiente();
        }

        return  sum;
    }
};

int main() {
    ListaSuma miLista;

    miLista.insertarPrimero(6);
    miLista.insertarPrimero(2);
    miLista.insertarPrimero(5);
    miLista.insertarPrimero(3);
    miLista.insertarPrimero(4);

    miLista.print();

    cout << "Resultado: " << miLista.sumaDesde(3) << std::endl; // Debe dar 15
    return 0;
}

