/* [Ejercicio 17]:
Hacer una función que dada una frase ingresada por teclado la imprima invertida.
Implementar la función con la estructura de datos vista más adecuada.
*/

#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

void invertirFrase(Pila<string>& pl){

    string frase="una imagen vale mas que mil palabras";
    string word="";

    for(int i=0;i<frase.length();i++) {
        if(frase[i]==' '){
            pl.push(word);
            word="";
        } else {
            word = word + frase[i];
        }
    }

    pl.push(word);

    while(!pl.esVacia()) {
        word = pl.peek();
        cout<<word<<" ";
        pl.pop();
    }
    cout<<endl;

}


int main(){
    Pila<string> pl;

    cout<<"Frase invertida: ";
    invertirFrase(pl);

    return 0;
}