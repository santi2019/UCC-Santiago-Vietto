#ifndef PLANTILLA_ARBOLBINARIO_H
#define PLANTILLA_ARBOLBINARIO_H

#include "NodoArbol.h"
#include <iostream>

template <class T> class ArbolBinario {
private:
    NodoArbol<T> *root;     //Puntero a la raiz.
public:
    ArbolBinario();

    void put(T data);

    T search(T data);

    void remove(T data);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

    void espejo();

    //Metodos para finales:

    int getLevel(T v);                   //Toma el nivel del valor ingresado.

    int sumarNivelPerValue(int value);   //Suma todo el nivel del valor ingresado.

    int sumarNivel(int nivel);           //Suma todos los valores del nivel ingresado.

    int sumarDesdeNivel(int nivel);      //Suma todos los valores incluido el del nivel ingresado.

    int LevelCounter();                  //Cuenta los niveles que tiene el arbol, recuerda que el nivel 0 es la raiz.

    int sumarDesdeNivelPorRama(int nivel, int rama);  //Suma todos los valores incluido el del nivel ingresado, pero solo de la rama especificada. [1]IZQ - [0]DER.

    int getLevelPerValue(int value, int *levelCatch);      //Devuelve el nivel de un valor.

    int sumarNivelesAnteriores(int value);      //Suma los valores de niveles anteriores.

    void sumaHojas(int total);             //Suma las hojas que no tengan hijos.

private:  //Metodos de sobrecarga privados.
    T search(T data, NodoArbol<T> *r);   //Recibe el valor a buscar y un puntero al nodoArbol (raiz).
    NodoArbol<T> *put(T data, NodoArbol<T> *r);   //Recibe el valor a insertar y un puntero al nodoArbol (raiz).
    NodoArbol<T> *remove(T data, NodoArbol<T> *r);  //Recibe el valor a remover y un puntero al nodoArbol (raiz).
    NodoArbol<T> *findMax(NodoArbol<T> *r, bool *found);  //Recibe un puntero al nodoArbol y un bool.
    void preorder(NodoArbol<T> *r);
    void inorder(NodoArbol<T> *r);
    void postorder(NodoArbol<T> *r);
    void espejo(NodoArbol<T> *r);

    //Metodos para finales:
    int getLevel(T v, int currentLevel, NodoArbol<T> *r);
    int sumarNivel(int nivel, NodoArbol<T> *r, int *total);
    int sumarDesdeNivel(int nivel, NodoArbol<T> *r, int *total);
    int LevelCounter(NodoArbol<T> *r, int levelCount, int *levelCatch);
    int sumarNivelesAnteriores (int nivel, NodoArbol<T> *r, int *total, int *level);
    int getLevelPerValue(int value, NodoArbol<T> *r, int levelCount, int *levelCatch);
    int sumarDesdeNivelPorRamaIzq(int nivel, NodoArbol<T> *r, int *total, bool rama);
    int sumarDesdeNivelPorRamaDer(int nivel, NodoArbol<T> *r, int *total, bool rama);
    void sumaHojas(NodoArbol<T> *r, int total);
};



/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> ArbolBinario<T>::ArbolBinario() {
    root = nullptr;         //Inicializamos la raiz en nullo
}



/**
 * Destructor del Arbol
 */
template <class T> ArbolBinario<T>::~ArbolBinario() {}



/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T ArbolBinario<T>::search(T data) {
    return search(data, root);        //Llamamos a la funcion privada. Mandamos el dato y la raiz (puntero nodoArbol).
}

/*Este metodo lo usamos dentro del metodo search publico*/
template <class T> T ArbolBinario<T>::search(T data, NodoArbol<T> *r){

    if(r == nullptr){      //Verimicamos si el arbol esta vacio.
        throw 404;         //Tiramos error porque no existe el arbol.
    }

    if(r->getData() == data){     //Si el valor de la raiz es el dato que buscamos
        return r->getData();      //Devolvemos el dato.
    }

    if(r->getData() > data){                //Si el valor del nodo en el que estamos parados es mayor al que buscamos
        return search(data, r->getLeft());  //entonces debe estar en el lado izquierdo, por lo cual llamamos recursivamente
    }else{                                  //a la funcion pero le pasamos por parametro el dato y el nodo de la izquierda.
        return search(data, r->getRight()); //Caso contrario buscamos por la derecha.
    }

}



/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void ArbolBinario<T>::put(T data) {
    root = put(data, root);         //Sobreescribimos la raiz con la sobrecarga privada en base a el dato que queremos
}                                   //remover y nuestro primer nodo que es la raiz.

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> NodoArbol<T> *ArbolBinario<T>::put(T data, NodoArbol<T> *r) {

    if(r == nullptr){                   //Verificamos si el arbol esta vacio. Creamos un nuevo nodo en la raiz.
        return new NodoArbol<T>(data);  //Por sobrecarga pasamos el dato y lo devuelve.
    }

    if(r->getData() == data){           //Si el valor del nodo en el que estamos parados es igual al que ingresamos.
        throw 404;                      //Tiramos error porque no puede haber valores repetidos.
    }

    if(r->getData() > data){                   //Si el valor del nodo en el que estamos parados es mayor al que ingresamos
        r->setLeft(put(data, r->getLeft())); //entonces ingresa en el lado izquierdo, por lo cual llamamos recursivamente
    }else{                                     //a la funcion pero le pasamos por parametro el dato y el nodo de la izquierda.
        r->setRight(put(data, r->getRight())); //Caso contrario ingresamos en la derecha.
    }

    return r;                           //Devolvemos la raiz modificada en base al dato que insertamos.
}



/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T> void ArbolBinario<T>::remove(T data) {
    root = remove(data, root);     //Sobreescribimos la raiz con la sobrecarga privada en base a el dato que queremos
}                                  //remover y nuestro primer nodo que es la raiz.

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r) {
    NodoArbol<T> *aux;             //variable aux para guardar el puntero de la referencia que no queremos perder.

    if(r == nullptr){              //Si el valor del nodo que buscamos no existe o se elimino antes (arbol vacia).
        throw 404;                 //Tiramos error porque ese nodo no existe.
    }

    if(r->getData() == data){      //Si estamos en el nodo que tiene el dato que queremos remover.

        if(r->getLeft() == nullptr && r->getRight() == nullptr){ //1º caso: el nodo no tiene hijos (ni der ni izq).
            delete r;            //Eliminamos el nodo directamente.
            return nullptr;      //Devolvemos null porque ya no hay mas nada.

        }else if(r->getLeft() != nullptr && r->getRight() == nullptr){ //2º caso: el nodo no tiene hijo der pero si izq.
            aux = r->getLeft();  //Guardamos el nodo izq en aux para no perderlo.
            delete r;            //Eliminamos el nodo directamente.
            return aux;          //Devolvemos aux, y queda definido como la nueva raiz del arbol.

        }else if(r->getLeft() == nullptr && r->getRight() != nullptr){ //3º caso: el nodo no tiene hijo izq pero si der.
            aux = r->getRight(); //Guardamos el nodo der en aux para no perderlo.
            delete r;            //Eliminamos el nodo directamente.
            return aux;          //Devolvemos aux, y queda definido como la nueva raiz del arbol.

        }else if(r->getLeft() != nullptr && r->getRight() != nullptr){ //4º caso: el nodo tiene ambos hijos.

            if(r->getLeft()->getRight != nullptr){  //Si el nodo izq tiene algo a su derecha. Buscamos el maximo.
                bool found;        //Variable para afirmar si encontramos o no el maximo.
                aux = findMax(r->getLeft(), &found); //Almacenamos el maximo temporalmente en aux. Pasamos el dato del lado izq.
                aux->setRight(r->getRight());    //A la derecha del maximo ponemos lo que estaba a la derecha del nodo que eliminamos.
                aux->setLeft(r->getLeft());      //Hacemos lo mismo para la izquierda, y reordenamos el arbol.

            }else{
                aux =  r->getLeft();        //Caso contrario, almacenamos la parte izquierda.
                r->getLeft()->setRight(r->getRight()); //Y le setamos la zona derecha, lo que estaba a la derecha del nodo original
            }

            delete r;     //Eliminamos el nodo donde estamos parados.
            return aux;   //Devolvemos el auxiliar.
        }

    }else if (r->getData() > data){                //Si el valor del nodo en el que estamos parados es mayor al que ingresamos
        r->setLeft(remove(data, r->getLeft()));  //entonces ingresa en el lado izquierdo, por lo cual llamamos recursivamente
    }else{                                         //a la funcion pero le pasamos por parametro el dato y el nodo de la izquierda.
        r->setRight(remove(data, r->getRight())); //Caso contrario ingresamos en la derecha.
    }

    return r;     //Asigna a la nueva raiz reordenada.
}

/*Funcion auxiliar para la funcion remove*/
template <class T> NodoArbol<T> *ArbolBinario<T>::findMax(NodoArbol<T> *r, bool *found) {
    NodoArbol<T> ret;    //Nodo retorno, que utilizamos para devolver el maximo.
    *found = false;      //Instanciamos nuestra variable de encontrado como falso.

    if(r->getRight() == nullptr){    //Si no hay nada del lado derecho.
        *found = true;               //Encontramos el mayor/maximo.
        return r;                    //Devolvemos el nodo.
    }

    ret = findMax(r->getRight(), found); //El retorno siempre esta del lado derecho, porque es el mas grande (iterador).

    if(*found){                    //Si se encontro el maximo.
        r->setRight(nullptr)    //Seteamos el nuevo nodo derecho como nulo (no hay nada mas grande que ese valor).
        *found = false;            //Frenamos los ciclos recursivos y evite seguir bajando por la rama.
    }

    return ret;    //Devolvemos nuestro maximo y lo usamos en el metodo remove.
}



/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T> bool ArbolBinario<T>::esVacio() {
    return root == nullptr;    //Si la raiz es nula significa que el arbol esta vacio.
}



/**
 * Recorre un árbol en preorden
 * Imprime el arbol
 */
template <class T> void ArbolBinario<T>::preorder() {
    preorder(root);   //Llamamos a la funcion privada. Mandamos el dato y la raiz (puntero nodoArbol).
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> void ArbolBinario<T>::preorder(NodoArbol<T> *r) {

    if(r == nullptr){    //Si el arbol esta vacio.
        return;          //Simplemente no imprime nada.
    }

    std::cout << r->getData() << " ";   //Primero se imprime la raiz.
    preorder(r->getLeft());             //De forma recursiva recorremos el arbol hacia la iquierda y mostramos.
    preorder(r->getRight());            //Luego si no hay mas, vuelve al nodo raiz y continua a la derecha y mostramos.
}



/**
 * Recorre un árbol en orden
 * Imprime el arbol
 */
template <class T> void ArbolBinario<T>::inorder() {
    inorder(root);   //Llamamos a la funcion privada. Mandamos el dato y la raiz (puntero nodoArbol).
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> void ArbolBinario<T>::inorder(NodoArbol<T> *r) {

    if(r == nullptr){    //Si el arbol esta vacio.
        return;          //Simplemente no imprime nada.
    }

    inorder(r->getLeft());             //Primero se imprime lo que esta a la izquierda (lo que es menor).
    std::cout << r->getData() << " ";  //Luego se imprime la raiz.
    inorder(r->getRight());            //Y por ultimo se imprime lo que esta a la deracha (lo que es mayor).
}



/**
 * Recorre un árbol en postorden
 * Imprime el arbol
 */
template <class T> void ArbolBinario<T>::postorder() {
    postorder(root);   //Llamamos a la funcion privada. Mandamos el dato y la raiz (puntero nodoArbol).
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> void ArbolBinario<T>::postorder(NodoArbol<T> *r) {

    if(r == nullptr){    //Si el arbol esta vacio.
        return;          //Simplemente no imprime nada.
    }

    postorder(r->getLeft());            //Primero se imprime lo que esta a la izquierda (lo que es menor).
    postorder(r->getRight());           //Luego se imprime lo que esta a la deracha (lo que es mayor).
    std::cout << r->getData() << " ";   //Y por ultimo se imprime la raiz.
}



/**
 * Muestra un árbol por consola
 */
template <class T> void ArbolBinario<T>::print() {
    if (root != NULL){
        root->print(false, "");
    }
}



/**
 * Metodo espejo
 */
template<class T> void ArbolBinario<T>::espejo() {
    espejo(root);   //Llamamos a la funcion privada. Mandamos el dato y la raiz (puntero nodoArbol).
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> void ArbolBinario<T>::espejo(NodoArbol<T> *r) {

    if(r == nullptr) {
        return;
    }else{
        espejo(r->getLeft());
        espejo(r->getRight());

        NodoArbol<T> *aux = r->getLeft();
        r->setLeft(r->getRight());
        r->setRight(aux);
    }

}



/**
 * Obtener el nivel
 * Toma el nivel del valor ingresado.
 */
template <class T> int ArbolBinario<T>::getLevel(T v){
    return getLevel(v, 0, root);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> int ArbolBinario<T>::getLevel(T v, int currentLevel, NodoArbol<T> *r){

    if (r == nullptr){             //Si no se encuentra el nivel se devuelve excepción con valor 404
        throw 404;
    }

    if (r->getData() == v){
        return currentLevel;
    }

    if (r->getData() > v){         //Si el valor actual es mayor al del nodo se busca por la rama derecha.
        return getLevel(v, currentLevel + 1, r->getLeft());
    }
    else{                          //De lo contrario el valor del nodo se busca por la rama izquierda.
        return getLevel(v, currentLevel + 1, r->getRight());
    }
}



/** [Ejercicio 23]
 * Sumar Nivel
 * Suma todos los valores del nivel ingresado.
 */
template <class T> int ArbolBinario<T>::sumarNivel(int nivel){
    int suma = 0;
    return sumarNivel(nivel, root, &suma);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> int ArbolBinario<T>::sumarNivel(int nivel, NodoArbol<T> *r, int *total){

    if (nivel == 0){
        if( r!=nullptr ) {
            *total = *total + r->getData();
        }
    }

    if(r->getLeft()!=nullptr){
        sumarNivel(nivel-1, r->getLeft(), total);
    }

    if(r->getRight()!=nullptr){
        sumarNivel(nivel-1, r->getRight(), total);
    }

    return *total;
}



/**[Ejercicio 23]
 * Sumar desde nivel
 * Suma todos los valores incluido el del nivel ingresado
 */
template <class T> int ArbolBinario<T>::sumarDesdeNivel(int nivel){
    int suma=0;
    return sumarDesdeNivel(nivel, root, &suma);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> int ArbolBinario<T>::sumarDesdeNivel(int nivel, NodoArbol<T> *r, int *total){

    if (nivel<=0){
        if( r!=nullptr ) {
            *total = *total + r->getData();
        }
    }

    if(r->getLeft()!=nullptr){
        sumarDesdeNivel(nivel-1, r->getLeft(), total);
    }

    if(r->getRight()!=nullptr){
        sumarDesdeNivel(nivel-1, r->getRight(), total);
    }

    return *total;
}



/**
 * Contador de nivel
 * Cuenta los niveles que tiene el arbol
 * Recuerda que el nivel 0 es la raiz
 */
template <class T> int ArbolBinario<T>::LevelCounter(){
    int levelCount = 0;
    int levelCatch = 0;
    return LevelCounter(root, levelCount, &levelCatch);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> int ArbolBinario<T>::LevelCounter(NodoArbol<T> *r, int levelCount, int *levelCatch) {

    if( *levelCatch<levelCount ) {
        *levelCatch= levelCount;
    }

    if(r->getLeft()!=nullptr){
        LevelCounter(r->getLeft(), levelCount+1, levelCatch);
    }

    if(r->getRight()!=nullptr) {
        LevelCounter(r->getRight(), levelCount+1, levelCatch);
    }

    return *levelCatch;
}



/**
 * Suma desde nivel por rama
 */
template <class T> int ArbolBinario<T>::sumarNivelesAnteriores(int value){
    int level = this->getLevel(value);
    int suma = 0;
    int nivel = 0;
    return sumarNivelesAnteriores(nivel, root, &suma, &level);
}

template <class T> int ArbolBinario<T>::sumarNivelesAnteriores(int nivel, NodoArbol<T> *r, int *total,int *level){

    if (nivel!=*level){
        if( r!=nullptr ) {
            *total = *total + r->getData();
        }
    }

    if(r->getLeft()!=nullptr){
        sumarNivel(nivel+1, r->getLeft(), total);
    }

    if(r->getRight()!=nullptr){
        sumarNivel(nivel+1, r->getRight(), total);
    }

    return *total;
}



/**
 * Obterner nivel por valor
 */
template <class T> int ArbolBinario<T>::getLevelPerValue(int value, int *levelCatch){
    int levelCount = 0;
    return getLevelPerValue(value, root, levelCount, levelCatch);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template <class T> int ArbolBinario<T>::getLevelPerValue(int value, NodoArbol<T> *r, int levelCount,int *levelCatch){

    if(r->getData()==value) {
        *levelCatch= levelCount;
        return *levelCatch;
    }

    if(r->getLeft()!=nullptr){
        getLevelPerValue(value, r->getLeft(), levelCount+1, levelCatch);
    }

    if(r->getRight()!=nullptr){
        getLevelPerValue(value, r->getRight(), levelCount+1, levelCatch);
    }

}



/**
 * Sumar nivel por valor
 */
template <class T> int ArbolBinario<T>::sumarNivelPerValue(int value)
{
    int levelCatch=0;
    getLevelPerValue(value, &levelCatch);
    return sumarNivel(levelCatch);
}



/** [Ejercicio 24]
 * Obterner nivel por valor
 */
template <class T> int ArbolBinario<T>::sumarDesdeNivelPorRama(int nivel, int rama){
    int suma=0;
    if (rama == 0){
        return sumarDesdeNivelPorRamaIzq(nivel, root, &suma, false); // TRUE: Se suma la raiz/nivel 0. FALSE: No se suma la raiz/nivel 0;
    }
    else {
        return sumarDesdeNivelPorRamaDer(nivel, root, &suma, false); // TRUE: Se suma la raiz/nivel 0. FALSE: No se suma la raiz/nivel 0;
    }
}

template <class T> int ArbolBinario<T>::sumarDesdeNivelPorRamaIzq(int nivel, NodoArbol<T> *r, int *total, bool rama){

    if (nivel<=0){
        if( r!=nullptr && rama) {
            *total = *total + r->getData();
        }

    }

    if(r->getLeft()!=nullptr){
        sumarDesdeNivelPorRamaIzq(nivel-1, r->getLeft(), total, false);
    }

    if(r->getRight()!=nullptr){
        sumarDesdeNivelPorRamaIzq(nivel-1, r->getRight(), total, true);
    }

    return *total;
}

template <class T> int ArbolBinario<T>::sumarDesdeNivelPorRamaDer(int nivel, NodoArbol<T> *r, int *total, bool rama){

    if (nivel<=0){
        if( r!=nullptr && rama) {
            *total = *total + r->getData();
        }
    }

    if(r->getLeft()!=nullptr){
        sumarDesdeNivelPorRamaDer(nivel-1, r->getLeft(), total, true);
    }

    if(r->getRight()!=nullptr){
        sumarDesdeNivelPorRamaDer(nivel-1, r->getRight(), total, false);
    }

    return *total;
}



/** [Ejercicio 22]
 * Sumar hojas
 */
template<class T> void ArbolBinario<T>::sumaHojas(int total){
    sumaHojas(root, total);
}

/*Esta funcion privada la usamos dentro de la search publica*/
template<class T> void ArbolBinario<T>::sumaHojas(NodoArbol<T> *r, int total){


    if(r == nullptr){
        return;
    }

    if(r->getLeft() == nullptr && r->getRight() == nullptr){
        total = total + r->getData();
    }

    if(r->getLeft() != nullptr){
        sumaHojas(r->getLeft(), total);
    }

    if(r->getRight() != nullptr) {
        sumaHojas(r->getRight(), total);
    }

    std::cout<<total;
}


#endif //PLANTILLA_ARBOLBINARIO_H