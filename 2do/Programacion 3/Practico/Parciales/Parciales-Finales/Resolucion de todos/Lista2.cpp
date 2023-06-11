/* [Ejercicio 2]
Escribir un programa que permita agregar no enteros a una lista de números aceptada por
teclado. El programa pregunta si debe agregar al principio, al final o en el medio (tamaño/2) y agrega el
elemento a la lista.
*/


#include "./Estructuras/Lista.h"
#include <iostream>
using namespace std;

int main() {
    Lista<float> list2;       //Declaramos una lista de tipo float (no int).
    bool keepAdding = true;   //Variable para seguir agregando o frenar el ciclo de ingreso por pantalla.
    float newValue = 0;       //Variables a ingresar (nuevo valor).
    int pos = 0;              //Variable posicion que representa donde queremos agregar (1. inicio, 2. medio, 3.final).
    int size = 0;             //Declaramos el tamaño de la lista, inicialmente 0 porque no tiene nada.
    char addValue;            //Variable para continuar añadiendo o salir.

    while(keepAdding){        //Ciclo para el ingreso, siempre que sea true sigue corriendo y si es false se detiene.

        size = list2.getTamanio();      //Asignamos size como el tamaño de la lista.

        if(size > 0){                   //Segun el tamaño de la lista tenemos las opciones de posiciones.
            cout<<"Donde desea ingresar valor en la lista: "<<endl;
            cout<<"1. Al inicio"<<endl;
            cout<<"2. Al medio"<<endl;
            cout<<"3. Al final"<<endl;
            cout<<"Ingresar: ";
            cin>>pos;
        }else{
            cout<<"Como la lista esta vacia, el proximo valor se agregara al comienzo!"<<endl;
            pos = 1;
        }

        cout<<endl;
        cout<<"Valor a ingresar: ";     //Ingresamos el valor del dato a introducir en la lista.
        cin>>newValue;
        cout<<endl;

        switch(pos){                    //Segun el valor de posicion que elija el usuario instanciamos las opciones.
            case 1:{
                list2.insertarPrimero(newValue);        //Insertamos valor al inicio.
            }break;

            case 2:{
                list2.insertar(size/2,newValue);   //Insertamos valor en el medio.
            }break;

            case 3:{
                list2.insertarUltimo(newValue);         //Insertamos valor al final.
            }break;

            default:{
                cout<<"Valor de posicion ingresado incorrecto!"<<endl;  //Cuando el usuario elige una opcion incorrecta.
            }break;
        }

        cout<<endl;
        cout<<"Lista actualizada:"<<endl;        //Mostramos la lista modificada.
        list2.print();
        cout<<endl;

        cout<<"Si desea seguir agregando a la lista seleccione:"<<endl
            <<"s. [continuar]"<<endl
            <<"Cualquier letra. [cancelar]"<<endl
            <<"Ingresar: ";
        cin>>addValue;
        cout<<endl;

        if(addValue != 's'){                         //Si el valor ingresado es distinto de s. Caso contrario seguimos.
            keepAdding = false;                      //Declaramos la variable keepAdding como false.
            cout<<"Programa finalizado"<<endl;       //Salimos del ciclo while.
        }
    }

    cout<<endl;
    cout<<"Lista final: "<<endl;          //Mostramos la lista final.
    list2.print();

    return 0;
}
