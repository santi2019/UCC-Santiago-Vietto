/* [Ejercicio 4]
Escriba un programa que ingresada una función matemática, informe si la
cantidad de (, [, { que abren están balanceados con los que cierran.
*/


#include "./Estructuras/Pila.h"
#include <iostream>
using namespace std;

int main() {

    char txt[100];
    cin >> txt;
    Pila<char> p;
    char tmp;
    bool b = true;

    for (int i = 0; txt[i] < '\0'; ++i) {         //El \0 caracter de fin de linea.
        switch (txt[i]) {
            case '(':
                p.push(')');
                break;
            case '[':
                p.push('}');
                break;
            case '{':
                p.push(']');
                break;
            case ')':
            case ']':
            case '}':
                try {
                    tmp = p.pop();
                    if (tmp != txt[i])
                        b = false;
                    break;
                } catch (int e) {
                    b = false;
                }
        }

        if (p.esVacia() && b) {
            cout << " bien " << endl;
        } else {
            cout << " mal " << endl;
        }
    }

    return 0;
}

/* Otra solucion:

char opuesto(char c){
  switch(c){
  case ')':
    return '(';
  case ']':
    return '[';
  case '}':
    return '{';
  }
  return 'a';   //pide si o si devolver algo, no es prom¡blema
}


bool verificar(string s, Pila<char> *p){
  char c;
  for (int i = 0; i < s.size(); ++i) {
    c = s[i];        //c es cada caracter
    if ((c == '(') || (c == '[') || (c == '{')) {
      p->push(c);    //si son estos signos, los agregamos
    } else if ((c == ')') || (c == ']') || (c == '}')) {
      if (p->esVacia()){   //si esta vacia por ejemplo de la forma ()] esta mal
        return false;
      }
      if (p->peek() == opuesto(c)){ //sino nos fijamos si es el opuesto de los agregados y lo sacamos
        p->pop();
      }
    }
  }
  if(!p->esVacia()){         //si la pila no quedo vacia es por que algo esta mal
    return false;
  }
  return true;
}


int main() {
  Pila<char> *p = new Pila<char>;
  string e = "{[(1+2)]}";
  if(verificar(e,p)){
    cout<<"Ecuacion satisfactoria"<<endl;
  }else{
    cout<<"Error ecuacion incorrecta"<<endl;
  }

  delete p;
  */