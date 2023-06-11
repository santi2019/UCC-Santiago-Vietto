/* [Ejercicio 14]:
Implementar un método a la clase lista que reciba un parámetro V y que
encuentre el nodo con dicho valor y lo mueva una posición hacia adelante (no se
pueden crear nuevos nodos ni eliminar nodos).
*/

#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;

template<class T> class ListaExamen : public Lista<T>{
public:
    void adelantar(int V) {
        Nodo<T> *aux = this->inicio;
        int pos=0;

        if (aux == nullptr){
            throw 404;
        }

        if(aux->getDato() == V){
            return;
        }

        else if(pos == 0 && (aux->getSiguiente()->getDato() == V)){
            Nodo<T> *aux2 = aux->getSiguiente();
            aux->setSiguiente(aux2->getSiguiente());
            aux2->setSiguiente(this->inicio);
            this->inicio = aux2;
        }

        else{
            while (aux != nullptr && aux->getSiguiente()->getSiguiente()->getDato() != V) {
                aux = aux->getSiguiente();
                pos++;
            }
            Nodo<T> *aCambiar = aux->getSiguiente()->getSiguiente();
            aux->getSiguiente()->setSiguiente(aCambiar->getSiguiente());
            aCambiar->setSiguiente(aux->getSiguiente());
            aux->setSiguiente(aCambiar);
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

    cout<<"Ingrese el valor para mover hacia delante: ";
    cin>>_num;

    miLista.adelantar(_num);

    cout<<endl;
    cout<<"Lista actualizada: " << endl;
    miLista.print();
    cout<<endl;

    /*
    cout<<"Movido el 7 de nuevo"<<endl;
    miLista.adelantar(7);
    miLista.print();

    std::cout << std::endl << "Movido el 5" << std::endl;
    miLista.adelantar(5);
    miLista.print(); */

    return 0;
}