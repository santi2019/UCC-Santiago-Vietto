#ifndef U03_PILAS_PILA_PILA_H_
#define U03_PILAS_PILA_PILA_H_

#include "nodo.h"
#include "iostream"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Pila {
private:
  Nodo<T> *topNode;
public:
  Pila();

  ~Pila();

  void push(T dato);

  T pop();

  bool esVacia();

  T peek();                                //Puntero a la direccion de memoria del primer nodo

  void insertAfter2(int , int , int );     //Devuelve la posicion donde se inserto el nuevo valor

  int getTamanio();

  void toString ();
};



/**
 * Constructor de la clase Pila
 * @tparam T
 */
template <class T> Pila<T>::Pila() {
  topNode = nullptr;          //Inicializa vacia. El tope apunta a null.
}



/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Pila<T>::~Pila() {
  while( topNode != nullptr ){          //Siempre que el tope no apunte al puntero nullptr (pila no este vacia).
    pop();                              //Desalojamos memoria.
  }
}



/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Pila<T>::push(T dato) {

  Nodo<T> *newNode = new Nodo<T>;       //Creamos e inicializamos un nuevo nodo.
  newNode->setDato( dato );          //Seteamos el valor del dato en el nuevo nodo.
  newNode->setSiguiente( topNode );     //El nuevo nodo siempre va a apuntar al tope actual que tenemos de la pila.
  topNode = newNode;                    //El tope pasa a ser el nuevo nodo (nuevo tope) que agregamos ultimamente.

}



/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Pila<T>::pop() {
  T data;                             //Dato a devolver, de tipo template.
  Nodo<T> *toErase = topNode;         //Nodo auxiliar para tomar el ultimo nodo de la pila y eliminarlo. Lo guardamos
                                      //temporalmente para no perderlo.
  if( topNode == nullptr ){           //Si la lista esta vacia (el tope apunta a nullptr).
    throw 404;                        //Tiramos error porque no podemos quitar nada.
  }

  data = topNode->getDato();            //Guardamos en el dato a devolver el valor del tope actual.
  topNode = topNode->getSiguiente();    //Asiganamos el tope de la pila al siguiente nodo del tope actual a borrar.

  delete toErase;                      //Desalojamos de la memoria el viejo valor del tope guardado en la variable aux.
  return data;                         //Devolvemos el dato.
}



/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Pila<T>::esVacia() {
  return topNode == nullptr;           //Le preguntamos al tope de la pila si es el puntero nulo o no.
}



/**
 * Devuelve el valor tope de la  pila sin borrarlo
 * @tparam T
 * @return
 */
template <class T> T Pila<T>::peek() {
    T tope;                            //Dato a devolver, de tipo template.
    tope = topNode->getDato();         //Guardamos en el dato a devolver el valor del tope actual.
    return tope;                       //Devolvemos el dato.
}



/**
 * Inserta un dato en la pila
 * @tparam int
 * @param variable actual, numero de veces que se repite, variable a rremplazar
 */
template <class T> void Pila<T>::insertAfter2(int oldValue, int n, int newValue) {
    Nodo<T> *newNode = new Nodo<T>;    //Creamos e inicializamos un nuevo nodo.
    newNode->setDato(newValue);     //Seteamos el nuevo valor del dato en el nuevo nodo.
    Nodo<T> *actualNode = topNode;     //Nodo auxiliar para tomar el ultimo nodo de la pila. Lo guardamos temporalmente
                                       //para no perderlo.
    int count = 0;                     //Registro de las veces que se encontro el valor.

    while(actualNode != nullptr){                     //Recorremos la pila mientras no encontremos el final.
        if(actualNode->getDato() == oldValue){        //Si encontramos una ocurrencia.
            count++;                                  //Incrementamos el contador.
        }

        if(count == n){                                         //Una vez encontrado el numero de ocurrencias.
            newNode->setSiguiente(actualNode->getSiguiente());  //El nuevo nodo apunta al siguiente de la ultima ocurrencia.
            actualNode->setSiguiente(newNode);                  //El nodo de la ultima ocurrencia apunta ahora al nuevo.
            return;
        }

        actualNode = actualNode->getSiguiente();   //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
    }
}



/**
 * Devuelve el tamaño de la pila
 *
 */
template <class T> int Pila<T>::getTamanio() {
    Nodo<T> *actual = topNode;                //Variable aux que apunta al tope.
    int size = 0;                             //Contador que arranca a cero.

    while(actual != nullptr){                 //Mientras la pila no este vacia.
        actual = actual->getSiguiente();      //Nos desplazamos al siguiente nodo, de esta
        size++;                               //manera podemos incrementar size.
    }

    return size;                              //Devolvemos el tamaño.

}



/**
 * Devuelve todo el contenido de la pila
 *
 */
template <class T> void Pila<T>::toString() {
    Nodo<T> *actual = topNode;                         //Variable aux que apunta a inicio.
    while (actual != nullptr) {                        //Mientras la variable auxiliar no sea el final (nullptr).
        std::cout << actual->getDato() << std::endl;   //A medida que avanza lee los datos de dicho nodo.
        actual = actual->getSiguiente();         //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
    }

    std::cout << "NULL" << std::endl;                  //Cuando termina el ciclo, al final de la lista muestra NULL.
}


#endif // U03_PILAS_PILA_PILA_H_