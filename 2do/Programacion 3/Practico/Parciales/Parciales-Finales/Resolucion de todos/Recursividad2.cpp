/* [Ejercicio 2]
Implemente una función recursiva que, teniendo un array ingresado
por teclado, me devuelva la suma de todos sus elementos.
 */

#include <iostream>
using namespace std;

int sumatoria(int *arr, unsigned int size) {
    //Si el tamaño es cero (la posicion es cero) devolvemos el unico valor del arreglo en esa posicion.
    if(size == 0){
        return arr[size];
    }

    return arr[size] + sumatoria(arr, size-1);
}


int main() {
    int size;
    int arr[size];  //*arr

    cout<<"Ingrese la cantidad de elementos del array: ";
    cin>>size;
    cout<<endl;

    for(int i=0; i<size; i++){
        cout<<"Ingrese el numero "<<i<<": ";
        cin>>arr[i];
        cout<<endl;
    }

    cout<<"Sumatoria de los elementos del array: "<<sumatoria(arr, size-1)<<endl;

    return 0;
}







/* Solucion parcial 1:  (otra forma)

int suma(int arr[], int size) {
 int s = 0;
    if (size == 0) {
        s += arr[0];
    }else {
       s = arr[size] + suma(arr, size-1);
    }
  return s;
}

int main() {
    int arreglo[] = {1, 2, 3};
    int _suma;
    _suma = suma(arreglo, 3-1);

    cout << "La suma del arreglo es: " << _suma <<endl;

    return 0;
}

*/