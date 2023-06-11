/* [Ejercicio 5]:
Escribir una función recursiva que tenga solo un parámetro entero positivo n y muestre
en la pantalla ese número de asteriscos **”*”**, todos en una línea.
*/

#include <iostream>
using namespace std;

void secuencia(int n){
    if(n == 0){
        return;
    }

    if(n > 0){
        cout << "*";
    }
    secuencia(n-1);
}


int main(){
    int n;

    cout<<"Ingrese el numero de asteriscos: ";
    cin>>n;
    cout<<endl;

    cout << "Secuencia: ";
    secuencia(n);

    return 0;

}