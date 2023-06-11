/* [Ejercicio 1]
Implemente una función para potencias enteras con recursividad.
Definición recursiva para elevar un número a una potencia:
Un número elevado a la potencia cero produce la unidad; la
potencia de un número se obtiene multiplicándolo por sí mismo
elevando a la potencia menos uno. Por ejemplo:

3<sup>2</sup>=3*(3<sup>1</sup>)=3*[3*(3<sup>0</sup>)]=3*(3*1)=9
*/

#include <iostream>
using namespace std;

unsigned int potencia(unsigned int base, unsigned int exp) {
    //Si el exponente es cero devolvemos uno sin importar el valor de la base.
    if(exp == 0){
        return 1;
    }

    return base * potencia(base, exp-1);
}


int main() {
    int base, exp;

    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<endl;

    cout<<"Ingrese el exponente: ";
    cin>>exp;
    cout<<endl;

    cout<<"El resultado de la potencia es: "<<potencia(base, exp)<<endl;

    return 0;
}