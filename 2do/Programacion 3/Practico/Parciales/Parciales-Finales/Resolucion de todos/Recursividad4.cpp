/* [Ejercicio 4]
Algoritmo de Euclides: mostrar que el máximo común divisor (mcd) de "a" y "b",
(a > b > 0), es igual a "a" si "b" es cero, en otro caso es igual al mcd de "b"
y el remanente de "a" dividido por "b", si b > 0.
*/

#include <iostream>
using namespace std;

unsigned int mcd(unsigned int a, unsigned int b) {
    if(b == 0){
        return a;  //Es igual a a si b es cero
    }

    return mcd(b , a%b);  //En otro caso, si b > 0, es igual al mcd de b y el remanente de a dividido por b
}


int main() {

    int a, b;

    cout<<"Ingrese primer numero: ";
    cin>>a;
    cout<<endl;

    cout<<"Ingrese segundo numero: ";
    cin>>b;
    cout<<endl;

    cout<<"El maximo comun divisor es: "<<mcd(a, b)<<endl;

    return 0;
}
