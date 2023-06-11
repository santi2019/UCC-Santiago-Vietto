/* [Ejercicio 1]
Diseñar una aplicación que permita: Cargar en un array 30 números generados
aleatoriamente entre 100 y 500. Imprimir los números. Crear un árbol binario
de búsqueda con los datos del array.
*/


#include "./Estructuras/ArbolBinario.h"
#include <iostream>
#include "stdlib.h"
#include "time.h"

using namespace std;

int main() {

    ArbolBinario<int> arbol;
    int a[30];

    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        a[i] = 100 + rand()%(501-100);
        arbol.put(a[i]);
    }

    cout<<"Arbol en inorden: "<<endl;
    arbol.inorder();

    return 0;
}

/*
Ingresar a arbol enteros y mostrar en todos los orden

    ArbolBinario<int> arbol;
    int n, a;


    cout << "ingrese cantidad de nodos: ";
    cin >> n;
    cout<<endl;

    for (int i = 0; i < n; ++i) {
        cout << " Numero a ingresar en el arbol " << endl;
        cin >> a;
        arbol.put(a);
    }

    cout << "Arbol en inorder: " << endl;
    arbol.inorder();

    cout << endl;
    cout << "Arbol en postorder: " << endl;
    arbol.postorder();

    cout << endl;
    cout << "Arbol en preorder: " << endl;
    arbol.preorder();

}
*/