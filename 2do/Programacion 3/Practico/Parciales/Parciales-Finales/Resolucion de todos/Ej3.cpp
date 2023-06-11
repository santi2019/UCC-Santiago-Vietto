/*[Ejercicio 3]:
Describir qué hace la siguiente función; si es recursiva o iterativa. Si es una
función recursiva, realizar su versión iterativa. Si es una función iterativa, realizar su
versión recursiva.
*/

/* La funcion anterior es iterativa ya que no se esta llamando a si mismo, por lo tanto busca un
   numero en un arreglo si lo encuentra retorna true, de lo contrario false, e itera sobre las posiciones
   del arreglo. */

#include <iostream>
using namespace std;

void numeroEncontrado(int arr[], int size, int num, int index){

    if(arr[index] == num){
        cout<<"Numero encontrado! es: "<< num <<endl;
    }else{
        if(index == size){
            cout<<"Numero no encontrado! "<<endl;
        }else{
            numeroEncontrado(arr, size, num, index+1);
        }
    }
}


int main() {

    int arreglo[] = {1, 2, 3, 4, 5};
    int _num;

    cout<<"Ingresar numero para buscar: ";
    cin>>_num;

    cout<<endl;
    numeroEncontrado(arreglo, 4, _num, 0);

    /* El cuarto parametro de la funcion corresponde al indice que se va a ir incrementando
       para recorrer el arreglo, pero si le pasas de entrada index = 4 = tamaño del arreglo,
       nunca vas a pasar del primer ciclo recursivo, encontrando unicamente el ultimo valor
       del arreglo si se busca dicho valor, sino no se encuentra ningun valor. Pasando este
       parametro con index = 0 funciona correctamente */

    return 0;
}





