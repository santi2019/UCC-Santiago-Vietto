/* [Ejercicio 11]:
Implementar un método a la clase lista que reciba como parámetro un valor D. El
método debe buscar este valor y moverlo a la última posición (solo moviendo enlaces,
no creando nodos nuevos).
*/

#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;

class ListaExamen : public Lista<int> {
public:
    void alUltimo(int D) {
        Nodo<int> *temp = inicio;
        Nodo<int> *prev = nullptr;
        Nodo<int> *nodes = nullptr;
        Nodo<int> *current = nullptr;

        if(this->inicio == nullptr){
            cout<<"Lista vacia"<<endl;
        }else{
            while(temp != nullptr){
                current = temp;
                temp = temp->getSiguiente();
                if(current->getDato() == D) {
                    if (this->inicio == current) {
                        this->inicio = temp;
                    }
                    if (prev != nullptr) {
                        prev->setSiguiente(temp);
                    }
                    current->setSiguiente(nodes);
                    nodes = current;
                }else{
                    prev = current;
                }
            }

            if(this->inicio == nullptr && nodes != nullptr){
                this->inicio = nodes;
            }else if(prev != nullptr && nodes != nullptr){
                prev->setSiguiente(nodes);
            }else{
                cout<<"Ocurrencia no encontrada"<<endl;
            }

        }
    }
};


int main() {
    ListaExamen miLista;
    int _num;

    miLista.insertarUltimo(3);
    miLista.insertarUltimo(4);
    miLista.insertarUltimo(7);
    miLista.insertarUltimo(5);

    miLista.print();
    cout<<endl;

    cout<<"Ingrese el valor para insertar al ultimo: ";
    cin>> _num;

    miLista.alUltimo(_num);

    cout<<endl;
    cout << "Lista actualizada: " << endl;
    miLista.print();
    cout<<endl;

    return 0;
}