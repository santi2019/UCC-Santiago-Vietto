#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_

#include "nodo.h"
#include "iostream"

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
protected:
  Nodo<T> *inicio;     //Puntero al inicio

public:
  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  void remover(int pos);

  T getDato(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  void print();

  int insertAfter2(T oldValue, int n, T newValue);     //Devuelve la posicion donde se inserto el nuevo valor

  int tamanio(Nodo<T> *n);

  int tamanio() {         //Ejercicio parcial
        tamanio(inicio);
  }

};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() {
    inicio = nullptr;      //Inicializa vacia. El inicio apunta a null.
}



/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) {   //Recibe como parametro la referencia de otra lista.
    inicio = li.inicio;                                    //El nuevo inicio, es el inicio de la lista que pasamos.
}



/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() {
    vaciar();                             //Desalojamos memoria.
}



/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() {
    return inicio == nullptr;                 //Le preguntamos al tope de la pila si es el puntero nulo o no.
}



/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
  Nodo<T> *aux = inicio;      //Variable aux que apunta a inicio.
  int size = 0;               //Contador que arranca a cero.

  while (aux != nullptr) {        //Mientras no encontremos el final de la lista.
    aux = aux->getSiguiente();    //Nos desplazamos al siguiente nodo, de esta
    size++;                       //manera podemos incrementar size.
  }

  return size;                    //Devolvemos el tamaño.
}



/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato) {
    Nodo<T> *aux = inicio;              //Variable aux que apunta a inicio.
    Nodo<T> *nuevo;                     //Nuevo nodo que vamos a incertar.
    int posActual = 0;                  //Iterador que nos ayuda a saber donde estamos. Arranca del inicio.

    nuevo = new Nodo<T>;                //Instanciamos un nuevo nodo vacio.
    nuevo->setDato(dato);            //Insertamos un dato al nodo nuevo.

    if (pos == 0) {                       //Si queremos insertar en la posicion inicial.
        nuevo->setSiguiente(inicio);      //El nuevo nodo pasa a ser el inicio.
        inicio = nuevo;                   //Guardamos el dato de inicio, y pasa a la 2da pos.
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {    //Queremos llegar a la posicion anterior de la posicion elegida.
        aux = aux->getSiguiente();                     //Iteracion al proximo nodo, nos desplazamos.
        posActual++;                                   //Incrementamos para saber la posicion en la que estamos.
    }

    if (aux == nullptr) {           //Si la posicion que buscamos no existe o se elimino antes (es nullptr).
        throw 404;                  //Tiramos error porque esa posicion no existe.
    }

    nuevo->setSiguiente(aux->getSiguiente());    //El nodo a insertar va a ser el siguiente del cual estamos apuntando.
    aux->setSiguiente(nuevo);                    //Hacemos el enlace al nodo que esta delante del que insertamos.
}



/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);      //Llamamos a la funcion insertar y asignamos pos 0 y el dato.
}



/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
  Nodo<T> *aux = inicio;            //Variable aux que apunta a inicio.
  Nodo<T> *nuevo;                   //Nuevo nodo que vamos a incertar.

  nuevo = new Nodo<T>;              //Instanciamos un nuevo nodo vacio.
  nuevo->setDato(dato);          //Insertamos un dato al nodo nuevo.

  if (aux == nullptr) {             //En caso de que la lista este vacia.
    nuevo->setSiguiente(inicio);    //Ponemos el nuevo nodo al inicio de la lista. El inicio anterior apuntaba a null.
    inicio = nuevo;                 //Ahora el inicio es el nuevo nodo.
    return;
  }

  while (aux->getSiguiente() != nullptr) {    //Mientras la variable aux no sea el final, confirmamos que no sea
      aux = aux->getSiguiente();              //el puntero null para llegar al anterior y registrar el nuevo nodo ahi.
  }

  nuevo->setSiguiente(aux->getSiguiente());   //El nodo a insertar va a ser el siguiente del cual estamos apuntando.
  aux->setSiguiente(nuevo);                   //Hacemos el enlace al nodo que esta delante del que insertamos.
}



/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
    Nodo<T> *aux = inicio;          //Variable aux que apunta a inicio.
    Nodo<T> *aBorrar;               //Nodo que vamos a borrar.
    int posActual = 0;              //Iterador que nos ayuda a saber donde estamos. Arranca del inicio.

  if (pos == 0) {                           //Si queremos borrar el primer nodo de la lista.
    inicio = inicio->getSiguiente();        //El inicio pasa a ser el siguiente nodo de la lista. El 2do al que apunta.
    delete aux;                             //Borramos la variable auxiliar (inicio que ya no necesitamos).
    return;
  }

  while (aux != nullptr && posActual < pos - 1) {     //Queremos llegar a la posicion anterior de la posicion elegida.
      aux = aux->getSiguiente();                      //Iteracion al proximo nodo, nos desplazamos.
      posActual++;                                    //Incrementamos para saber la posicion en la que estamos.
  }

    if (aux == nullptr) {           //Si la posicion que buscamos no existe o se elimino antes (lista vacia).
        throw 404;                  //Tiramos error porque esa posicion no existe.
    }

  aBorrar = aux->getSiguiente();               //El nodo a borrar va a ser el siguiente del cual estamos apuntando.
  aux->setSiguiente(aBorrar->getSiguiente());  //Hacemos el enlace al nodo que esta delante del que borramos.
  delete aBorrar;                              //No borramos aux porque es un nodo existente, sino que borramos aBorrar.
}



/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
  Nodo<T> *aux = inicio;           //Variable aux que apunta a inicio.
  int posActual = 0;               //Iterador que nos ayuda a saber donde estamos. Arranca del inicio.

  while (aux != nullptr && posActual < pos) {       //Queremos llegar a la posicion del nodo que queremos.
    aux = aux->getSiguiente();                      //Iteracion al proximo nodo, nos desplazamos.
    posActual++;                                    //Incrementamos para saber la posicion en la que estamos.
  }

  if (aux == nullptr) {           //Si la posicion que buscamos no existe o se elimino antes (lista vacia).
      throw 404;                  //Tiramos error porque esa posicion no existe.
  }

  return aux->getDato();     //Leemos el nodo y devolvemos el contenido del dato.
}



/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
    Nodo<T> *aux = inicio;           //Variable aux que apunta a inicio.
    int posActual = 0;               //Iterador que nos ayuda a saber donde estamos. Arranca del inicio.

    while (aux != nullptr && posActual < pos) {       //Queremos llegar a la posicion del nodo que queremos.
        aux = aux->getSiguiente();                    //Iteracion al proximo nodo, nos desplazamos.
        posActual++;                                  //Incrementamos para saber la posicion en la que estamos.
    }

    if (aux == nullptr) {           //Si la posicion que buscamos no existe o se elimino antes (lista vacia).
        throw 404;                  //Tiramos error porque esa posicion no existe.
    }

    aux->setDato(dato);          //De esta manera se sobreescribe el dato que estaba antes y reemplazamos.

}



/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio;          //Variable aux que apunta a inicio.
    Nodo<T> *aBorrar;               //Nodos que vamos a borrar.

	while( aux != nullptr ){         //Mientras la variable auxiliar no sea el final (nullptr).
		aBorrar = aux;               //Hacemos que el nodo aBorrar sea el auxiliar. Arrancamos por el inicio.
        aux = aux->getSiguiente();   //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
        delete aBorrar;              //Borramos el nodo.
    }

    inicio == nullptr;    //Una vez que borramos todos los nodos de la lista,
                          //inicio debe apuntar a nullptr para que siga

}



/**
 * Función que muestra los valores de la lista
 * Sirve para llamar desde el objeto e imprimir
 * todos los valores de la lista
 */
template<class T> void Lista<T>::print() {
    Nodo<T> *aux = inicio;           //Variable aux que apunta a inicio.

    while(aux != nullptr){                   //Mientras la variable auxiliar no sea el final (nullptr).
        std::cout<<aux->getDato()<<"->";     //A medida que avanza lee los datos de dicho nodo.
        aux = aux->getSiguiente();           //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
    }

    std::cout << "NULL" << std::endl;        //Cuando termina el ciclo, al final de la lista muestra NULL.
}



/**
 * Función Ejercicio 6
 * Incerta un nuevo valor despues de la n-esima
 */
template <class T> int Lista<T>::insertAfter2(T oldValue, int n, T newValue) {
    Nodo<T> *aux = inicio;       //Variable aux que apunta a inicio.
    int ocurrences = 0;          //Registro de las veces que se encontro el valor.
    int currentPosition = 0;     //Valor de la posicion donde se inserta el nuevo dato.

    if(n == 0){                                //Significa que no va a tener ocurrencias.
        insertarPrimero(newValue);        //Por ende insertamos primero.
        return 0;
    }

    while(aux->getSiguiente() != nullptr && ocurrences<n){  //Si el siguiente de aux no sea nullptr
                                                            //y las ocurrencias son menores a las que queremos buscar.
        if(oldValue == aux->getDato()){  //Si encontramos una ocurrencia.
            ocurrences++;                //Incrementamos el contador.
        }
        aux = aux->getSiguiente();     //Hacemos que el auxiliar sea el siguiente (iteracion al proximo nodo).
        currentPosition++;             //A la par sumamos hasta llegar a la posicion y dar su numero
    }

    if( ocurrences == n){                              //Una vez encontrado el numero de ocurrencias.
        insertar(currentPosition, newValue); //Insertamos un valor en la posicion en la que llegamos.
    }else {
        return -1;                     //De esta manera sabemos que no se inserto el valor en la lista.
    }
}


/**
 * Función [Ejercicio 8]
 */
template<class T> int Lista<T>::tamanio(Nodo<T> *n){

    if(n == nullptr){
        return 0;
    }else{
        return 1 + tamanio(n->getSiguiente());
    }
}


#endif // U02_LISTAS_LISTA_LISTA_H_