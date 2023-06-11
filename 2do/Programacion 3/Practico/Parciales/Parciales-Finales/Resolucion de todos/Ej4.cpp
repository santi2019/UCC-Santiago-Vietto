/* [Ejercicio 4]:
Escriba una función void recursiva que reciba como parámetro solo un entero positivo n
y que despliegue todos los enteros impares menores a n.
*/

#include <iostream>
using namespace std;

void imparesMenores(int n){

    if(n == 0){
        return;
    }

    if(n%2 != 0){
        cout<< n <<" ";
    }
    imparesMenores(n - 1);
}


int main(){
    int n;

    cout<<"Ingrese el numero: ";
    cin>>n;
    cout<<endl;

    cout << "Numeros impares menores: ";
    imparesMenores(n);

    return 0;

}