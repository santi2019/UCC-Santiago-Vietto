/* [Ejercicio 18]:
Realice una función que reciba una pila por referencia y un número. La función debe
sacar la primera ocurrencia de dicho valor de la pila.
*/

#include <iostream>
#include "Estructuras/Pila.h"
#include "Estructuras/Cola.h"
using namespace std;

void removerPrimerOcurrencia(Pila<int>& pl, int n){
    Cola<int> col;
    int datoRemover;

    if (pl.esVacia()){
        return;
    }

    while(!pl.esVacia()){
        datoRemover = pl.pop();
        if(datoRemover == n){
            cout<<"Valor removido: "<< datoRemover << endl;
        }else{
            col.encolar( datoRemover );
        }
    }

    while( !col.esVacia() ){
        pl.push( col.peek() );
        col.desencolar();
    }
}

int main(){
    Pila<int> pl;

    pl.push(9);
    pl.push(3);
    pl.push(5);
    pl.push(2);
    pl.push(3);

    removerPrimerOcurrencia(pl, 5);

    while(!pl.esVacia()){
        cout<< pl.pop() <<endl;
    }

    return 0;
}
