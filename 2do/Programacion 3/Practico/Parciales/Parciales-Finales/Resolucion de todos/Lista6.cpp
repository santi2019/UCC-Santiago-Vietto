/* [Ejercicio 6]
Agregue el método: insertAfter2(int oldValue, int n, int newValue) que inserte
un nodo con el valor newValue después de la enésima ocurrencia de oldValue.
*/


#include "./Estructuras/Lista.h"
#include <iostream>
using namespace std;

int main() {
    Lista<int>  list6;

    for (int i = 0; i < 10; ++i) {
        list6.insertarUltimo(i);
    }

    list6.insertar(3,2);
    list6.insertar(7,2);

    cout<<"Lista orginal:"<<endl;
    list6.print();

    int newPosition = list6.insertAfter2(2,3,99);

    if(newPosition >= 0){
        cout<<"Se agrego un nuevo valor en la posicion "<<newPosition<<endl;
        list6.print();
    }else{
        cout<<"No se encontro el valor con las ocurrencias requeridas"<<endl;
    }

    return 0;
}