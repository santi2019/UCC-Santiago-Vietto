/* [Ejercicio 5]
Escribir segmentos de programa que lleven a cabo de forma
recursiva, cada una de las siguientes tareas:

1. Calcule la parte entera del cociente, cuando
el entero a se divide por el entero b.
2. Calcule el resto entero, cuando el entero a es
dividido por el entero b.
3. Utilice los módulos 1. y 2. para escribir una función recursiva que dado
        un entero no negativo lo imprima como una serie de dígitos separados por
espacios.

Ej: dado el entero 1024, debe escribir "1 0 2 4"
*/


#include <iostream>
using namespace std;

/* 1. Calculamos el cociente de forma recursiva */
unsigned int cociente(unsigned int a, unsigned int b) {
    if (b > a) {
        return 0;
    }

    return 1 + cociente(a - b, b);  //El 1 son las veces que entra b en a
}

/* 2. Calculamos el resto de forma recursiva */
unsigned int resto(unsigned int a, unsigned int b) {
    if (b > a) {
        return a;
    }

    return resto(a - b, b);
}

/* 3. Mostramos los digitos espaciados de un numero, de forma recursiva */
void escribir_espaciado(unsigned int num) {
    int c = cociente(num, 10); //Dividimos por 10 el numero
    int r = resto(num, 10);    //El resto es el numero por separado que mostramos

    if (c > 0) {
        escribir_espaciado(c);
    }

    cout << r << " "; //Se imprime el ultimo resto que se ejecuto
}



int main() {
    int a, b, num;

    cout<<"Ingrese el dividendo: ";
    cin>> a;
    cout<<endl;

    cout<<"Ingrese el divisor: ";
    cin>> b;
    cout<<endl;

    cout<<"Cociente: "<<cociente(a, b)<<endl;
    cout<<"Resto: "<<resto(a, b)<<endl;

    cout<<endl;
    cout<<"Ingrese numero para separar: ";
    cin>> num;
    cout<<endl;

    escribir_espaciado(num);

    return 0;
}









