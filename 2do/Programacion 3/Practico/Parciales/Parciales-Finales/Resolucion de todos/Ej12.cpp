/* [Ejercicio 12]:
Implementar un método a la clase lista que reciba como parámetro un valor D. El
método debe buscar este valor y moverlo a la segunda posición (solo moviendo enlaces,
no creando nodos nuevos).
*/

#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;

template <class T> class ListaExamen : public Lista<T> {
public:
    void alSegundo(T D) {
        Nodo<T> *aux = this->inicio;
        Nodo<T> *atras;

        if(aux->getDato() == D){
            this->inicio = this->inicio->getSiguiente();
            aux->setSiguiente(this->inicio->getSiguiente());
            this->inicio->setSiguiente(aux);
            return;
        }

        while(aux != nullptr){
            aux = aux->getSiguiente();
            if(aux->getDato() == D){
                atras->setSiguiente(aux->getSiguiente());
                aux->setSiguiente(this->inicio->getSiguiente());
                this->inicio->setSiguiente(aux);
                return;
            }
            atras = aux;
        }

    }
};


int main() {
    ListaExamen<int> miLista;
    int _num;

    miLista.insertarUltimo(3);
    miLista.insertarUltimo(4);
    miLista.insertarUltimo(7);
    miLista.insertarUltimo(5);

    miLista.print();
    cout<<endl;

    cout<<"Ingrese el valor para mover al segundo lugar: ";
    cin>>_num;

    miLista.alSegundo(_num);

    cout<<endl;
    cout<<"Lista actualizada: " << endl;
    miLista.print();
    cout<<endl;

    return 0;
}

