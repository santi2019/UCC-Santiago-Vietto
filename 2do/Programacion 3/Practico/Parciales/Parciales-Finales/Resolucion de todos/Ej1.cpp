/* [Ejercicio 1]:
Implemente una función recursiva que reciba como parámetro un array de enteros y
el tamaño y devuelva el valor más chico que encuentre en el array.
*/

#include <iostream>
using namespace std;

int minimo(int arr[], int size) {

    if(size == 0){
        return arr[size];
    }

    if(arr[size] < minimo(arr, size - 1)) {
        return arr[size];
    }else{
        return minimo(arr, size - 1);
    }
}


int main() {
    int arreglo[] = {15, 1, 71, 83, 9, 33, 233, 121, 81};

    cout << "El valor minimo en el arreglo es: " << minimo(arreglo, 8) << endl;
    return 0;
}