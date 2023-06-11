#ifndef PLANTILLA_NODOPRIORIDAD_H
#define PLANTILLA_NODOPRIORIDAD_H

template<class T>
class nodo {
private:
    T dato;
    nodo<T> *next;
    int prioridad;
public:
    nodo(T d, int p) {
        dato = d;
        next = nullptr;
        prioridad = p;
    }

    nodo(T d, nodo *n, int p) {
        dato = d;
        next = n;
        prioridad = p;
    }

    T setDato(T dato) {
        this->dato = dato;
    }

    T getDato() {
        return dato;
    }

    void setNext(nodo<T> *next) {
        this->next = next;
    }

    nodo<T>* getNext() {
        return next;
    }
};

#endif //PLANTILLA_NODOPRIORIDAD_H
