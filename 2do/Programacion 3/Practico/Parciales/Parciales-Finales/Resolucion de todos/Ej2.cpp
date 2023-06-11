/* [Ejercicio 2]:
Construir una función que sume los elementos de un arreglo de enteros recursivamente.
*/

#include <iostream>
using namespace std;

int sumaArreglo(int arr[], int size) {

    if(size == 0) {
        return arr[size];
    }

    return arr[size] + sumaArreglo(arr, size-1);
}

int main() {
    int arreglo[] = {1, 1, 1, 1, 1, 1, 2, 2, 2};
    int suma;

    suma = sumaArreglo(arreglo, 8);

    cout << "La suma del arreglo es: " << suma << endl;
    return 0;
}