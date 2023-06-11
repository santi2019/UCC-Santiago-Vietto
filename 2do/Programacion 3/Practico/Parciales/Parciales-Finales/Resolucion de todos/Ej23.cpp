/* [Ejercicico 23]:
Implementar un método de la clase árbol que reciba como parámetro un valor V y que
devuelva la suma de los valores de todos los nodos que se encuentren en los niveles
menores que el nodo que almacena el valor V (si es que este existe).
*/

#include "Estructuras/ArbolBinario.h"
#include <iostream>
using namespace std;

int sumarNivelesAnteriores(int valor, ArbolBinario<int> arb){
    int nivel = arb.getLevel(valor);
    int resultado = arb.sumarDesdeNivel(0) - arb.sumarDesdeNivel(nivel);
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


    cout << "Suma de los nodos en niveles menores donde se encuentra el valor '12': " << sumarNivelesAnteriores(12, arb) << endl;
    cout << "Suma de los nodos en niveles menores donde se encuentra el valor '3': " << arb.sumarDesdeNivelPorRama(3,5) << endl;

    return 0;
}
