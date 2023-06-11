/* [Ejercicio 5]
Se tiene la siguiente expresión infija:

(6+2)∗5−8/4

Realizar un programa en C++ que me calcule la expresión postfija.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    char txt[20] = "(6+2)*5-8/4";
    Pila<char> P;

    for (int i = 0; txt[i] != '\0'; ++i) {
        if (txt[i] == '+' || txt[i] == '*' || txt[i] == '-' || txt[i] == '/') {
            if (!P.esVacia()) {
                if ((P.peek() == '+' || P.peek() == '-')) {
                    P.push(txt[i]);
                } else {
                    cout << P.pop();
                    P.push(txt[i]);
                }
            } else
                P.push(txt[i]);
        } else
            cout << txt[i];
    }

    while (!P.esVacia()) {
        cout << P.pop();
    }

    return 0;
}












