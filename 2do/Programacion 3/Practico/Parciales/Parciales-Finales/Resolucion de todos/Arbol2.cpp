/* [Ejercicio 2]
Reconstruir un árbol binario a partir de los recorridos siguientes:

* Arbol 1

Preorden: 2, 5, 3, 9, 7, 1, 6, 4, 8.

Inorden: 9, 3, 7, 5, 1, 2, 6, 8, 4.

* Arbol 2

Inorden: 5, 6, 12, 10, 1, 9, 13, 4, 8, 2, 7, 3, 11.

Postorden: 6, 5, 10, 9, 1, 13, 12, 2, 8, 3, 11, 7, 4.
*/


#include "./Estructuras/ArbolBinario.h"
#include <iostream>
using namespace std;

int main() {
    ArbolBinario<int> arbol1;
    ArbolBinario<int> arbol2;
    int n, x, a, b;

    cout<<"ingrese cantidad de nodos del arbol 1: ";
    cin>>n; //9

    cout<<"ingrese cantidad de nodos del arbol 2: ";
    cin>>x; //13
    cout<<endl;

    for (int i = 0; i < n ; i++) {
        cout<<"Numero a ingresar en el arbol 1: ";
        cin>>a;
        arbol1.put(a);
        cout<<endl;
    }

    cout<<endl;
    cout<<"Arbol 1 en preorder: "<<endl;
    arbol1.preorder();

    cout<<endl;
    cout<<"Arbol 1 en inorder: "<<endl;
    arbol1.inorder();

    cout<<endl;
    cout<<endl;
    for (int i = 0; i < x ; i++) {
        cout<<"Numero a ingresar en el arbol 2: ";
        cin>>b;
        arbol2.put(b);
        cout<<endl;
    }

    cout<<endl;
    cout<<"Arbol 2 en inorder: "<<endl;
    arbol2.inorder();

    cout<<endl;
    cout<<"Arbol 2 en postorder: "<<endl;
    arbol2.postorder();

    return 0;
}