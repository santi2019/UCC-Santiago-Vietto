/* [Ejercicio 22]: casi salio
Implementar un método de la clase árbol que sume todos los valores de los nodos
Hoja, es decir de los nodos que no tienen hijos. Ejemplo, para el siguiente árbol, se
llama a la función de la siguiente forma:
*/

#include "Estructuras/ArbolBinario.h"
#include <iostream>
using namespace std;


int main(){
    ArbolBinario<int> arb;
    int total = 0;

    arb.put(4);
    arb.put(1);
    arb.put(8);
    arb.put(3);
    arb.put(6);
    arb.put(10);
    arb.put(5);
    arb.put(7);
    arb.put(9);

    cout << "Suma de las hojas: ";
    arb.sumaHojas(total);
    cout << endl;

    return 0;
}