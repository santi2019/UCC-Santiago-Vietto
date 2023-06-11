/* [Ejercicio 3]
Agregar la función peek a la clase pila que permita ver el valor del tope de pila sin sacarlo.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    Pila<int> p1, p2;
    int pila1, pila2;

    for (int i = 0; i < 10; i++) {
        p1.push(i + 1);
        p2.push(i * 2);
    }

    pila1 = p1.peek();
    pila2 = p2.peek();

    cout << "El tope de la pila 1 es: " << pila1<<endl;
    cout << "El tope de la pila 2 es: " << pila2<<endl;

    cout << "Pila 1: "<<endl;
    while (!p1.esVacia()) {
        pila1 = p1.pop();
        cout << pila1 <<endl;
    }

    cout<<endl;
    cout << "Pila 2: "<<endl;
    while (!p2.esVacia()) {
        pila2 = p2.pop();
        cout << pila2 <<endl;
    }

    cout<<endl;

    //No puedo poner los peek en esta parte porque ya estan borrados los elementos de las pilas.

    return 0;
}