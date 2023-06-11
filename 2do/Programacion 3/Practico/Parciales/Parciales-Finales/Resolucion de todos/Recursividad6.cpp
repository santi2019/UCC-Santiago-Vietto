/* [Ejercicio 6]
Calcular el factorial de un numero.
 */


#include <iostream>
using namespace std;

unsigned int factorial(unsigned int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n-1);
}


int main() {
    int n;

    cout<<"Ingrese el numero para obtener factorial: ";
    cin >> n;

    cout<<"El factorial del numero ingresado es: " <<  factorial(n) << endl;

    return 0;
}