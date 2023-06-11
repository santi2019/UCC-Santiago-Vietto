/* [Ejercicio 6]:
Implemente una función recursiva que devuelva verdadero si algún
valor del arreglo coincide con su índice.
*/

#include <iostream>
using namespace std;

bool indiceIgual(int arr[], int tam) {

    if(tam > 0){
        if(arr[tam-1] == tam-1){
            return true;
        }else{
            return indiceIgual(arr,tam-1);
        }
    }else{
        return false;
    }

}

int main(){
    int arr[] = {3, 5, 7, 3, 9, 325};

    cout<<endl;

    cout<<"El resultado es: " << indiceIgual(arr, 5) << endl;

    return 0;
}
