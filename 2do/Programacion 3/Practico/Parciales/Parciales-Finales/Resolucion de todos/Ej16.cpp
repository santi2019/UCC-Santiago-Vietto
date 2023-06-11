/* [Ejercicio 16]:
 * La funcionalidad deshacer comúnmente encontrada en los programas, mantiene
 * un historial ordenado de las operaciones que se realizaron. Cree un programa
 * que permita elegir 4 operaciones de un menú (subir, bajar, izq y der) y una
 * quinta opción que me permita deshacer. Al seleccionar la opción, el programa
 * escribirá “Se realizó operación [OPERACIÓN]” y si se selecciona deshacer,
 * deberá decir “Se deshizo [OPERACIÓN]”.
 */

#include <iostream>
#include "Estructuras/Pila.h"
using namespace std;

void printMenu(){
    cout << "Menu" << endl;
    cout << "1.Subir" << endl;
    cout << "2.Bajar" << endl;
    cout << "3.Izquierda" << endl;
    cout << "4.Derecha" << endl;
    cout << "5.Deshacer" << endl;
    cout << "6.Salir" << endl;
    cout << endl;
}

void getValue( int *input){
    cout << "Ingrese la operacion que desea realizar: ";
    cin >> *input;
    cout << endl;
}


class Memoria {
private:
    Pila<int> Historial;

public:
    void subir() {
        cout << "Se realizo la operacion 'Subir'" << endl;
        Historial.push(1);
    }

    void bajar() {
        cout << "Se realizo la operacion 'Bajar'" << endl;
        Historial.push(2);
    }

    void izq() {
        cout << "Se realizo la operacion 'Izquierda'" << endl;
        Historial.push(3);
    }

    void der() {
        cout << "Se realizo la operacion 'Derecha'" << endl;
        Historial.push(4);
    }

    void deshacer(){
        try{
            int unDo = Historial.pop();
            cout << "Se deshizo la operacion '";
            switch (unDo) {
                case 1:
                    cout << "Subir";
                    break;
                case 2:
                    cout << "Bajar";
                    break;
                case 3:
                    cout << "Izquierda";
                    break;
                case 4:
                    cout << "Derecha";
                    break;
            }
            cout << "'" << endl;

        }catch(int error){
            cout << endl;
            cout << "No hay operaciones para eliminar" << endl;
        }
    }
};

int main() {

    int opcion = 0;
    Memoria mem;

    while (opcion != 6) {
        printMenu();
        getValue(&opcion);

        switch (opcion) {
            case 1:
                mem.subir();
                break;
            case 2:
                mem.bajar();
                break;
            case 3:
                mem.izq();
                break;
            case 4:
                mem.der();
                break;
            case 5:
                mem.deshacer();
                break;
            case 6:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion incorrecta! Vuelva a intentar..." << endl;
                break;
        }
    }
    return 0;
}