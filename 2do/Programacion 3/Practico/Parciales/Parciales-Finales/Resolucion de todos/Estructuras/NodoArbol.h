#ifndef PLANTILLA_NODOARBOL_H
#define PLANTILLA_NODOARBOL_H

template <class T> class NodoArbol {
private:
    T data;                    //Dato de tipo en el que instanciemos la clase.
    NodoArbol *left, *right;   //Puntero del arbol a su nodo izquierdo y derecho.
public:
    NodoArbol(){              //Constructor sin parametros.
        left = nullptr;       //Inizializamos el puntero izquierdo en nulo.
        right = nullptr;      //Inizializamos el puntero derecho en nulo.
    }

    NodoArbol(T d){           //Constructor por parametros. Pasamos un dato por parametro.
        data = d;             //Inizializamos data.
        left = nullptr;       //Inizializamos el puntero izquierdo en nulo.
        right = nullptr;      //Inizializamos el puntero derecho en nulo.
    }

    T getData() const{        //const hace que no se pueda modificar nada de los atributos de la clase.
        return data;          //Devuelve un dato de tipo T. Muestra el dato que tiene el nodo.
    }

    void setData(T d){
        this->data = d;       //Recibe como parámetro un dato de tipo T. Seteamos el dato del nodo.
    }

    NodoArbol *getRight() const{   //const hace que no se pueda modificar nada de los atributos de la clase.
        return right;
    }

    void setRight(NodoArbol *r){
        this->right = r;           //Recibe como parámetro un dato puntero. Seteamos el dato del nodo.
    }

    NodoArbol *getLeft() const{    //const hace que no se pueda modificar nada de los atributos de la clase.
        return left;
    }

    void setLeft(NodoArbol *l){
        this->left = l;            //Recibe como parámetro un dato puntero. Seteamos el dato del nodo.
    }

};

#endif //PLANTILLA_NODOARBOL_H