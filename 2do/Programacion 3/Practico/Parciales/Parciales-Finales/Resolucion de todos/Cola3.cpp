/* [Ejercicio 3]
Agregue un método a la clase cola para insertar un nodo según un valor entero de prioridad.
El valor 0 es la máxima prioridad. Este método debe colocar el nodo lo mas próximo al frente
de la cola, pero atrás del ultimo nodo con la misma prioridad.
*/

#include "./ColaPrioridad.h"
#include <iostream>
using namespace std;

int main() {
    ColaPrioridades<int> c;

    for(int i = 10; i < 20; i++) {
        c.encolar(i, i % 3);
        cout << i << ' ';
    }

    cout<<"Desencolado: "<<endl;
    while(!c.esVacia()){
        cout << c.desencolar() << ' ';
    }

    return 0;
}