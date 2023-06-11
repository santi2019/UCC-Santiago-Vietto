/* [Ejercicio 3]
Algoritmo de Ackerman recursivo: es un algoritmo que basicamente
devuelve el numero de combinaciones de M objetos tomados de N objetos. */

#include <iostream>
using namespace std;

unsigned int ackerman(unsigned int m, unsigned int n) {
    //Tenemos el caso base
    if(m == 0){
        return (n+1);
    }

    if(m>0 && n==0){
        return ackerman(m-1, 1);
    }

    if(m>0 && n>0){
        return ackerman(m-1, ackerman(m, n-1));
    }

}


int main() {
    int m, n;

    cout<<"Ingrese el valor de m: ";
    cin>>m;
    cout<<endl;

    cout<<"Ingrese el valor de n: ";
    cin>>n;

    cout<<endl;
    cout<<"Resultado de ackerman:"<<ackerman(m, n)<<endl;

    return 0;
}