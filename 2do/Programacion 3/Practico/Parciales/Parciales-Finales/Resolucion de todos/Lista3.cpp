/* [Ejercicio 3]
Escribir un programa que permita eliminar elementos de una lista de números aceptada por
teclado. El programa pregunta qué elemento borrar considerando que el primero por la
izquierda es el 0.
*/


#include "./Estructuras/Lista.h"
#include <iostream>
using namespace std;

int main() {
    Lista<float> list3;
    bool keepAdding = true;
    bool keepDeleating = false;    //Variable para seguir eliminando o no.
    bool isLarger = true;
    float newValue = 0;
    int pos = 0, size = 0;
    char addValue;

    while(keepAdding){
        size = list3.getTamanio();

        if(size > 0){
            cout<<"Donde desea ingresar valor en la lista: "<<endl;
            cout<<"1. Al inicio"<<endl;
            cout<<"2. Al medio"<<endl;
            cout<<"3. Al final"<<endl;
            cout<<"Ingresar: ";
            cin>>pos;
            cout<<endl;
        }else{
            cout<<"Como la lista esta vacia, el proximo valor se agregara al comienzo!"<<endl;
            pos = 1;
        }

        cout<<"Valor a ingresar: ";
        cin>>newValue;
        cout<<endl;

        switch(pos){
            case 1:{
                list3.insertarPrimero(newValue);
            }break;

            case 2:{
                list3.insertar(size/2,newValue);
            }break;

            case 3:{
                list3.insertarUltimo(newValue);
            }break;

            default:{
                cout<<"Valor ingresado incorrecto!"<<endl;
            }break;
        }

        cout<<endl;
        cout<<"Lista actualizada:"<<endl;
        list3.print();
        cout<<endl;

        cout<<"Seguir agregando a la lista:"<<endl
            <<"s. [continuar] || Cualquier letra. [cancelar]"<<endl
            <<"Ingresar: ";
        cin>>addValue;
        cout<<endl;

        if(addValue != 's'){
            keepAdding = false;
        }
    };

    cout<<endl;
    cout<<"Lista rellenada: "<<endl;
    list3.print();
    cout<<endl;

    cout<<"Desea eliminar elemento de la lista:"<<endl
        <<"a. [aceptar] || Cualquier letra. [cancelar]"<<endl
        <<"Ingresar: ";
    cin>>addValue;
    cout<<endl;

    if(addValue == 'a') {
        keepDeleating = true;
    }

    while(keepDeleating) {
        size = list3.getTamanio();
        if (size > 0) {
            isLarger = true;
            while (isLarger) {
                cout << "Ingrese posicion del valor a eliminar: ";
                cin >> pos;
                cout << endl;

                if (pos >= size || pos < 0) {
                    cout << "La posicion seleccionada no existe, ingrese nuevamente" << endl;
                    cout<<endl;
                    isLarger = true;
                } else {
                    isLarger = false;
                }
            }

            list3.remover(pos);

            cout << endl;
            cout << "Lista actualizada: " << endl;
            list3.print();
            cout << endl;

            cout << "Seguir eliminando elementos de la lista:" << endl
                 << "s. [continuar] || Cualquier letra. [cancelar]" << endl
                 << "Ingresar: ";
            cin >> addValue;
            cout << endl;

            if (addValue != 's') {
                keepDeleating = false;
            }
        }else{
            cout<<"La lista esta vacia"<<endl;
            keepDeleating = false;
            cout<<"Programa finalizado"<<endl;
        }
    }

    cout<<"Programa finalizado"<<endl;
    cout<<"***Lista final***"<<endl;
    list3.print();
    return 0;
}

