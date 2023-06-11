/* [Ejercicio 10]:
Implementar un método a la clase lista que reciba como parámetro un valor D. El
método debe buscar este valor y moverlo a la primera posición (Solo moviendo
enlaces. No creando nodos nuevos).
*/

#include <iostream>
#include "Estructuras/Lista.h"
using namespace std;

class ListaExamen : public Lista<int> {
public:
    void alInicio(int D) {
        Nodo<int> *aux = inicio;
        Nodo<int> *atras;

        while(aux != nullptr){
            if(aux->getDato() == D){
                atras->setSiguiente(aux->getSiguiente());
                aux->setSiguiente(inicio);
                inicio = aux;
            }
            atras = aux;
            aux = aux->getSiguiente();
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

    cout<<"Ingrese el valor para insertar primero: ";
    cin>> _num;

    miLista.alInicio(_num);

    cout<<endl;
    cout << "Lista actualizada: " << endl;
    miLista.print();
    cout<<endl;

    return 0;
}