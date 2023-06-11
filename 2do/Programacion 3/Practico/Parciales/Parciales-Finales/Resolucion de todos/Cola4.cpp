/* [Ejercicio 4]
En un supermercado, se tiene sólo una caja habilitada para que los clientes puedan pagar
sus compras. La caja tiene prioridad para mujeres embarazadas. Dada esta situación, se
pide que se implemente un sistema que calcule la cantidad de productos comprados por
cada cliente y el monto total gastado, también la cantidad de embarazadas que accedieron a
la cola.
*/


#include "./Estructuras/Cola.h"
#include <iostream>
using namespace std;

int main() {

    Cola<char> c4;
    int cliente;
    int cantProductos, productosTotal = 0;
    float monto, montoTotal = 0;

    cout<<"Caja de supermercado"<<endl;
    do{
        cout<<endl;
        cout<<"Cliente que ingresa: "<<endl;
        cout<<"1- Normal"<<endl;
        cout<<"2- Embarazada"<<endl;
        cout<<"3- Salir"<<endl;
        cout<<"Ingrese tipo: ";
        cin>> cliente;
        cout<<endl;

        switch (cliente) {
            case 1:
                c4.encolar(1);
                cout << "cantidad de productos: ";
                cin >> cantProductos;
                cout<<endl;
                cout << "Costo a pagar: ";
                cin >> monto;
                break;
            case 2:
                c4.prioridad(2, 0);
                cout << "cantidad de productos: ";
                cin >> cantProductos;
                cout<<endl;
                cout << "Costo a pagar: ";
                cin >> monto;
                break;
            case 3:
                cout << "Adios !" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                cout << endl;
                break;
        }
        productosTotal = productosTotal + cantProductos;
        montoTotal = montoTotal + monto;
    } while(cliente != 3);

    cout<<endl;
    cout<<"Cantidad de productos: "<< productosTotal <<endl;
    cout << "Monto total: "<< montoTotal;

    return 0;
}




