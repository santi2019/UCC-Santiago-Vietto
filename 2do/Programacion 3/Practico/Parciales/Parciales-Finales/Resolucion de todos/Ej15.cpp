/* [Ejercicio 15]:
Implementar un programa que dada una lista de valores enteros, encuentre todos los
números múltiplos de 3 y los reacomode al final de la lista en el orden inverso en el cual
fueron encontrados.
*/

#include <iostream>
#include "Estructuras/Lista.h"
#include "Estructuras/Pila.h"
using namespace std;

/*
class ListaExamen : public Lista<int> {
public:
    void multiplosAlUltimo(int D) {
        Nodo<int> *aux = inicio;
        Nodo<int> *aux2 = nullptr;
        Nodo<int> *aux3 = nullptr;
        Nodo<int> *actual = nullptr;

        if(this->inicio == nullptr){
            cout<<"La lista esta vacia"<<endl;
        }else{
            while(aux != nullptr){
                actual = aux;
                aux = aux->getSiguiente();
                if(actual->getDato() % D == 0) {
                    if (this->inicio == actual) {
                        this->inicio = aux;
                    }
                    if (aux2 != nullptr) {
                        aux2->setSiguiente(aux);
                    }
                    actual->setSiguiente(aux3);
                    aux3 = actual;
                }else{
                    aux2 = actual;
                }
            }

            if(this->inicio == nullptr && aux3 != nullptr){
                this->inicio = aux3;
            }else if(aux2 != nullptr && aux3 != nullptr){
                aux2->setSiguiente(aux3);
            }else{
                cout<<"Numero no encontrado"<<endl;
            }

        }
    }
};
*/

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

    for(int i=0; i < l.getTamanio(); i++){
        if(l.getDato(i) % 3 == 0 ){
            pl.push(l.getDato(i));
            //l.remover(i);
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

