#ifndef PLANTILLA_COLAPRIORIDAD_H
#define PLANTILLA_COLAPRIORIDAD_H

#include "./Estructuras/Cola.h"
#include "NodoPrioridad.h"
#define SIN_PRIORIDAD 1000000

template<class T> class ColaPrioridades {
private:
    nodo<T> *entrada[SIN_PRIORIDAD];
    nodo<T> *salida;
public:
    ColaPrioridades();

    ~ColaPrioridades();

    void encolar(T dato, int p);

    T desencolar();

    bool esVacia();
};


/**
 * Constructor de la clase ColaPrioridades
 * @tparam T
 */
template<class T>
ColaPrioridades<T>::ColaPrioridades() {
    for(int i = 0; i < SIN_PRIORIDAD; i++) {
        entrada[i] = nullptr;
    }
    salida = nullptr;
}


/**
 * Destructor de la clase ColaPrioridades, se encarga de liberar la memoria de todos los nodos
 * utilizados en la ColaPrioridades
 * @tparam T
 */
template<class T>
ColaPrioridades<T>::~ColaPrioridades() {}



/**
 * Inserta un dato en la ColaPrioridades
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void ColaPrioridades<T>::encolar(T dato, int p) {
    auto *nuevo = new nodo<T>(dato, p);

    if(entrada[p] != nullptr) {
        nuevo->setNext(entrada[p]->getNext());
        entrada[p]->setNext(nuevo);
    }else{
        nuevo->setNext(salida);
        salida = nuevo;
    }

    for(int i = p+1; i < SIN_PRIORIDAD; i++) {
        if(entrada[p] == entrada[i])
            entrada[i] = nuevo;
    }
    entrada[p] = nuevo;
}



/**
 * Obtener el dato de la ColaPrioridades
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T ColaPrioridades<T>::desencolar() {
    if(salida == nullptr)
        throw 1;
    T dato = salida->getDato();
    nodo<T> *salida_anterior = salida;
    salida = salida->getNext();

    for(int i = 0; i < SIN_PRIORIDAD; i++) {
        if(salida_anterior == entrada[i])
            entrada[i] = nullptr;
    }

    delete salida_anterior;
    return dato;
}



/**
 * Responde si la ColaPrioridades se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool ColaPrioridades<T>::esVacia() {
    return (salida == nullptr);
}

#endif //PLANTILLA_COLAPRIORIDAD_H
