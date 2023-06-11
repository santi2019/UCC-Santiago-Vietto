/* [Ejercicio 6]
Agregue el método: insertAfter2(int oldValue, int n, int newValue) que inserte un nodo
con el valor newValue después de la enésima ocurrencia de oldValue.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    Pila<int> p5;
    int tam;

    for (int i = 0; i < 10; ++i) {
        p5.push(1);
    }

    tam = p5.getTamanio();

    cout<<"Pila original: "<<endl;
    p5.toString();

    cout<<endl;
    cout<<"Tamanio de la pila: "<<tam;
    cout<<endl;

    p5.insertAfter2(1,4,3);
    cout<<"Pila nueva: "<<endl;
    p5.toString();
    cout<<endl;

    return 0;
}










