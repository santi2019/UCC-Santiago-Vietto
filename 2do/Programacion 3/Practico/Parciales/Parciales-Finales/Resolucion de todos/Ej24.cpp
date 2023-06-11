/* [Ejercicio 24]:
Implementar un método de la clase árbol que reciba como parámetro un valor V y que
devuelva la suma de los valores de todos los nodos que se encuentren en el mismo
nivel que el nodo que almacena el valor V (si es que este existe).
*/

#include "Estructuras/ArbolBinario.h"
#include <iostream>
using namespace std;

int sumarMismoNivel(int valor, ArbolBinario<int> arb){
    int nivel = arb.getLevel(valor);
    int resultado = arb.sumarNivel(nivel);
    return resultado;
}


int main() {
    ArbolBinario<int> arb;

    arb.put(15);
    arb.put(11);
    arb.put(26);
    arb.put(8);
    arb.put(12);
    arb.put(20);
    arb.put(30);
    arb.put(6);
    arb.put(9);
    arb.put(14);
    arb.put(35);

    cout << "Suma de los nodos en en el nivel donde se encuentra el valor '12': " << sumarMismoNivel(12, arb) << endl;

    return 0;
}