#ifndef NODO_H
#define NODO_H

//El nodo es de tipo template para que pueda adquirir cualquier tipo de dato.
template<class T> class Nodo{
    private:
        T dato;                  //Dato de tipo en el que instanciemos la clase.
        Nodo<T> *siguiente;      //Puntero que apunta al próximo nodo.
    
    public:
       T getDato(){              //Devuelve un dato de tipo T. Muestra el dato que tiene el nodo.
           return dato;
       }

       void setDato(T d){        //Recibe como parámetro un dato de tipo T. Seteamos el dato del nodo.
           dato = d;
       }

       Nodo<T> *getSiguiente(){  //Devuelve el puntero al siguiente nodo.
           return siguiente;
       }

       void setSiguiente(Nodo<T> *siguiente){   //Permite configurar el siguiente nodo al cual está apuntando el nodo
           this->siguiente = siguiente;         //sobre el que estamos llamando la función. Recibe como parámetro un
       }                                        //puntero a un nodo. Asignamos al atributo siguiente al nuevo que pasamos
                                                //por parámetro.
};

#endif //NODO_H