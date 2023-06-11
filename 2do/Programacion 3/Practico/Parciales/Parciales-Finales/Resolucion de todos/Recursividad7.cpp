/* [Ejercicio 7]
Calcular el la multiplicacion de dos enteros.
 */


#include <iostream>
using namespace std;

unsigned int multiplicacion(unsigned int a, unsigned int b){
    if(b == 1){
        return a;
    }

    return a + multiplicacion(a, b-1);
}


int main() {
    int a;
    int b;

    cout<<"Ingrese el primer numero: ";
    cin >> a;
    cout<<endl;

    cout<<"Ingrese el segundo numero: ";
    cin >> b;
    cout<<endl;

    cout<<"El resultado de la multiplicacion es: " <<  multiplicacion(a, b) << endl;

    return 0;
}