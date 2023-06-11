#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_

#include "nodo.h"
#include "iostream"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:
  Nodo<T> *topNode, *bottomNode;
public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  T peek();

  void toString ();

  void prioridad(T dato, int priori);
};



/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
  topNode = nullptr;                 //Inicializa vacia. El tope apunta a null.
  bottomNode = nullptr;              //Inicializa vacia. El fondo apunta a null.
}



/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {
  while( !esVacia() ){              //Siempre que el tope no apunte al puntero nullptr (pila no este vacia).
    desencolar();                   //Desencolamos.
  }
}



/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {
  Nodo<T> *newNode = new Nodo<T>();          //Creamos e inicializamos un nuevo nodo.
  newNode->setDato( dato );               //Seteamos el valor del dato en el nuevo nodo.
  newNode->setSiguiente(nullptr);            //El nuevo nodo siempre va al fondo, por eso siempre apunta a nullptr.

  if( bottomNode == nullptr ){               //Si el fondo es el puntero nulo.
    topNode = newNode;                       //El tope es el nuevo nodo que ingresamos.
  }else{
    bottomNode->setSiguiente(newNode);       //Caso contrario, el antiguo fondo apunta al nuevo nodo.
  }

  bottomNode = newNode;

}



/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {
  T aux;                                //Dato a devolver, de tipo template.
  Nodo<T> *toErase;                     //Nodo auxiliar para tomar el nodo de la cola y eliminarlo. Lo guardamos
                                        //temporalmente para no perderlo.

  if(bottomNode == nullptr){            //Si la pila esta vacia (el fondo apunta a nullptr).
      throw 404;                        //Tiramos error porque no podemos quitar nada.
  }

  aux = topNode->getDato();                 //Igualamos porque el tope es el valor que vamos a sacar primero siempre.
  toErase = topNode;                        //Hacemos la referencia del nodo a borrar.
  topNode = topNode->getSiguiente();        //Asignamos el nuevo frente/tope a el nodo del que quitamos.

  if( topNode == nullptr){              //Si el nodo que sacamos era el unico de la cola (tope ahora apunta a nulo).
    bottomNode = nullptr;               //El fondo debe apuntar a nulo.
  }

  delete toErase;                       //Desalojamos de la memoria el viejo valor del tope guardado en la variable aux.
  return aux;                           //Devolvemos el dato.
}



/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() {
  return bottomNode == nullptr;             //Si esto se cumple, entonces la cola esta vacia.
}



/**
 * Devuelve el valor fondo de la cola sin borrarlo
 * @tparam T
 * @return
 */
template <class T> T Cola<T>::peek() {
    T tope;                           //Dato a devolver, de tipo template.
    tope = topNode->getDato();        //Guardamos en el dato a devolver el valor del tope actual.
    return tope;                      //Devolvemos el dato.
}



/**
 * Devuelve todo el contenido de la cola
 *
 */
template <class T> void Cola<T>::toString() {
    Nodo<T> *actual = topNode;                        //Variable aux que apunta a inicio.
    while (actual != nullptr) {                       //Mientras la variable auxiliar no sea el final (nullptr).
        std::cout << actual->getDato() << std::endl;  //A medida que avanza lee los datos de dicho nodo.
        actual = actual->getSiguiente();              //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
    }
    std::cout << "NULL" << std::endl;                 //Cuando termina el ciclo, al final de la lista muestra NULL.
}



/**
 * Cola de prioridades
 *
 */
template <class T> void Cola<T>::prioridad(T dato, int priori) {
    Nodo<T> *newNodo = new Nodo<T>;
    newNodo->setDato(dato);
    newNodo->setSiguiente(nullptr);

    if(priori == 0) {
        if (bottomNode == nullptr) {
            topNode = newNodo;
        } else {
            bottomNode->setSiguiente(newNodo);
        }
    }

    bottomNode = newNodo;
}

#endif // U04_COLAS_COLA_COLA_H_
