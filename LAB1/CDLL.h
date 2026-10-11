#ifndef CDLL_H
#define CDLL_H

#include <iostream>
using namespace std;

template <typename T>
class NodoCDLL{
    private:
        T dato;
        NodoCDLL *next;
        NodoCDLL *prev;
    public:
        T getDato(){
            return this->dato;
        }
        void setDato(T pDato){
            this->dato = pDato;
        }
        NodoCDLL *getNext(){
            return this->next;
        }
        void setNext(NodoCDLL *pNext){
            this->next = pNext;
        }
        NodoCDLL *getPrev(){
            return this->prev;
        }
        void setPrev(NodoCDLL *pPrev){
            this->prev = pPrev;
        }
        NodoCDLL(T pDato, NodoCDLL *pNext = nullptr, NodoCDLL *pPrev = nullptr){
            this->dato = pDato;
            this->next = pNext;
            this->prev = pPrev;
        }
};

template <typename T>
class CDLL {
    private:
        NodoCDLL<T>* first;
        NodoCDLL<T>* tail;
        CDLL<T>* nextPerm;
        CDLL<T>* permFirst;
        CDLL<T>* permLast;

        void generarPermutaciones(NodoCDLL<T>* inicio, int n, NodoCDLL<T>* aux, int i);
        void agregarPermutacion(CDLL<T>* novaLista);
        void cleanPermu();

    public:
        CDLL();
        ~CDLL();

        int longitud();
        void insertarPosicion(int pos, T val);
        void push(T val);
        void append(T val);
        int remove(int pos);
        void mostrar();
        void mostrarPermu();
        CDLL<T>* permutar();
};

template <typename T>
CDLL<T>::CDLL() : first(nullptr), tail(nullptr),nextPerm(nullptr), permFirst(nullptr), permLast(nullptr) {}

template <typename T>
CDLL<T>::~CDLL() {
    if (!first) return;
    NodoCDLL<T>* aux = first;
    NodoCDLL<T>* nextNode;
    do {
        nextNode = aux;
        aux = aux->getNext();
        delete nextNode;
    } while (aux != first);
}

template <typename T>
int CDLL<T>::longitud() {
    int cont = 0;
    if (!first) return cont;
    NodoCDLL<T>* aux = first;
    do {
        cont++;
        aux = aux->getNext();
    } while (aux != first);
    return cont;
}

template <typename T>
void CDLL<T>::insertarPosicion(int pos, T val) {
    if (pos < 0 || pos > longitud()) {
        append(val);
    } else if (!pos) {
        push(val);
    } else {
        NodoCDLL<T>* aux = first;
        NodoCDLL<T>* prev = nullptr;
        for (int i=0; i<pos; i++) {
            prev = aux;
            aux = aux->getNext();
        }
        NodoCDLL<T>* nueva = new NodoCDLL<T>(val, aux, prev);
        prev->setNext(nueva);
        aux->setPrev(nueva);
    }
}

template <typename T>
void CDLL<T>::push(T val) {
    NodoCDLL<T>* nueva = new NodoCDLL<T>(val);
    if (first) {
        nueva->setNext(first);
        nueva->setPrev(tail);
        tail->setNext(nueva);
        first->setPrev(nueva);
        first = nueva;
    } else {
        first = tail = nueva;
        first->setNext(first);
        first->setPrev(first);
    }
}

template <typename T>
void CDLL<T>::append(T val) {
    NodoCDLL<T>* nueva = new NodoCDLL<T>(val);
    if (first) {
        nueva->setNext(first);
        nueva->setPrev(tail);
        tail->setNext(nueva);
        first->setPrev(nueva);
        tail = nueva;
    } else {
        first = tail = nueva;
        first->setNext(first);
        first->setPrev(first);
    }
}

template <typename T>
int CDLL<T>::remove(int pos) {
    if (pos < 0 || pos >= longitud()) {
        cout << "Posición fuera del rango" << endl; return 0;
    } else if (!pos) {
        NodoCDLL<T>* aux = first;
        if (first->getNext() == first) {
            delete first;
            first = tail = nullptr; return 0;
        }
        first = first->getNext();
        first->setPrev(tail);
        tail->setNext(first);
        int temp = aux->getDato(); delete aux; return temp;
    } else {
        NodoCDLL<T>* aux = first;
        NodoCDLL<T>* prev = nullptr;
        for (int i=0; i<pos; i++) {
            prev = aux;
            aux = aux->getNext();
            if (aux == first) return 0;
        }
        prev->setNext(aux->getNext());
        aux->getNext()->setPrev(prev);
        if (aux == tail) tail = prev;
        int temp = aux->getDato(); delete aux; return temp;
    }
}

template <typename T>
void CDLL<T>::mostrar() {
    if (!first) {
        cout << "" << endl;
        return;
    }
    NodoCDLL<T>* aux = first;
    do {
        cout << aux->getDato() << " ";
        aux = aux->getNext();
    } while (aux != first);
    cout << endl;
}

template <typename T>
CDLL<T>* CDLL<T>::permutar() {
    int n = longitud();
    generarPermutaciones(first, n, first, 0);
    return permFirst;
}

template <typename T>
void CDLL<T>::mostrarPermu() {
    CDLL<T>* aux = permFirst;
    while (aux) {
        aux->mostrar();
        aux = aux->nextPerm;
    }
    cleanPermu();
}

template <typename T>
void CDLL<T>::generarPermutaciones(NodoCDLL<T>* inicio, int n, NodoCDLL<T>* act, int i) {
    if (i == n) {
        CDLL<T>* novaLista = new CDLL<T>();
        NodoCDLL<T>* nodo = inicio;
        for (int j=0; j<n; j++) {
            novaLista->append(nodo->getDato());
            nodo = nodo->getNext();
        }
        agregarPermutacion(novaLista);
        return;
    }

    NodoCDLL<T>* aux = act ? act : inicio;
    for (int j=i; j<n; j++) {
        T temp = aux->getDato();
        aux->setDato(act->getDato());
        act->setDato(temp);

        generarPermutaciones(inicio, n, act->getNext(), i+1);

        temp = aux->getDato();
        aux->setDato(act->getDato());
        act->setDato(temp);
        aux = aux->getNext();
    }
}

template <typename T>
void CDLL<T>::agregarPermutacion(CDLL<T>* novaLista) {
    if (permFirst == nullptr) {
        permFirst = permLast = novaLista;
    } else {
        permLast->nextPerm = novaLista;
        permLast = novaLista;
    }
}

template <typename T>
void CDLL<T>::cleanPermu() {
    CDLL<T>* aux = permFirst;
    while (aux) {
        CDLL<T>* temp = aux;
        aux = aux->nextPerm;
        delete temp;
    }
    permFirst = permLast = nullptr;
}

#endif