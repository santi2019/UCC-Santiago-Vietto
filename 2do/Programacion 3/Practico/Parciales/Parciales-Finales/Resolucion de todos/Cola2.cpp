/* [Ejercicio 2]
Utilizando una pila y una cola, realizar una función que reciba una cadena y devuelva el
valor lógico verdadero si dicha cadena es un palidromo. No se deben tener en cuenta los
espacios y signos de puntuación.
Ejemplos de palidromo:

* anita lava la tina
* la ruta natural
* la ruta nos aporto otro paso natural
*/


#include "./Estructuras/Cola.h"
#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    char letra = ' ';
    Pila<char> pila;
    Cola<char> cola;

    cout<<"Ingrese una frase: ";

    while(letra != '.'){
        cin>>letra;
        pila.push(letra);
        cola.encolar(letra);
    }

    pila.pop(); //saco el punto de la pila

    while(!pila.esVacia()){
        if(pila.pop() != cola.desencolar()){
            cout<<"No es palindromo";
            return 0;
        }
    }

    cola.desencolar();

    if(!cola.esVacia()){
        cout<<"No es palindromo";
        return 0;
    }

    cout<<endl;
    cout<<"Es palindro";

    return 0;
}