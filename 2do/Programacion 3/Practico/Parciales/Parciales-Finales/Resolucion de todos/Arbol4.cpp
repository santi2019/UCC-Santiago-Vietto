/* [Ejercicio 4]
Especificar la operación espejo que devuelve la imagen
especular de un árbol binario.
*/


#include "./Estructuras/ArbolBinario.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


bool find(vector<int> &buf, int v) {
    for(int i = 0; i < buf.size(); i++) {
        if(buf[i] == v)
            return true;
    }
    return false;
}

int main() {
    ArbolBinario<int> *a = new ArbolBinario<int>();

    srand(time(NULL));

    vector<int> buf;
    for(int i = 0; i < 25; i++) {

        int num = rand() % 4000 + 200;

        if(find(buf, num)) {
            i--;
            continue;
        }

        buf.push_back(num);
        a->put(num);
    }

    cout<<"Arbol en inorden: "<<endl;
    a->inorder();
    cout << endl;

    cout<<"Arbol espejo: "<<endl;
    a->espejo();
    a->inorder();
    cout << endl;

    return 0;


}
