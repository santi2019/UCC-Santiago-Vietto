/* [Ejercicio 7]:
Implementar una función recursiva que acepte por parámetro un puntero de caracteres
(cadena) y un carácter, y que devuelva la cantidad de veces que aparece el carácter
dentro de la cadena.
*/

#include <iostream>
using namespace std;

int timesInWord(char *palabra, char letra){
    char *cadena;
    cadena = &palabra[1];

    if(palabra[0] == ' '){
        return 0;
    }

    if (palabra[0] == letra){
        return 1 + timesInWord(cadena,letra);
    }else{
        return timesInWord(cadena,letra);
    }

}

int main(){

    char letra = 's';
    char *palabra = "sol";

    cout<<endl;
    cout << "El caracter " << letra << " aparece " << timesInWord(palabra, letra) << " veces en la palabra " << palabra <<endl;

    return 0;
}