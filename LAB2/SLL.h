#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

template <typename T>
class NodoSLL{
    private:
        T dato;
        NodoSLL *next;
    public:
        T getDato(){
            return this->dato;
        }
        void setDato(T pDato){
            this->dato = pDato;
        }
        NodoSLL *getNext(){
            return this->next;
        }
        void setNext(NodoSLL *pNext){
            this->next = pNext;
        }
        NodoSLL(T pDato, NodoSLL *pNext = nullptr){
            this->dato = pDato;
            this->next = pNext;
        }
};

template <typename T>
class SLL{
    private:
        NodoSLL<T> *first;

        NodoSLL<T>* qs(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc);
        void solveQS(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc);

    public:
        int longitud();
        void insertarPosicion(int pos, T val);
        void push(T val);
        void append(T val);
        int remove(int pos);
        void mostrar();
        void ordenarRapido(int asc);
        NodoSLL<T>* getFirst();
        
        SLL();
        ~SLL();
};

template <typename T>
NodoSLL<T>* SLL<T>::getFirst(){
    return first;
}

template <typename T>
int SLL<T>::longitud(){
    NodoSLL<T> *aux = this->first;
    int cont=0;
    while(aux != NULL){
        cont++;
        aux = aux->getNext();
    }
    return cont;
}

template <typename T>
void SLL<T>::insertarPosicion(int pos, T val){
    if(pos < 0 || pos > this->longitud()){
        append(val);
    }
    else if(!pos){
        push(val);
    }
    else{
        NodoSLL<T> *aux = this->first;
        NodoSLL<T> *prev;
        for(int i=0;i<pos;i++){
            prev = aux;
            aux = aux->getNext();
        }
        NodoSLL<T> *nuevo = new NodoSLL<T>(val, aux);
        prev->setNext(nuevo);
    }
}

template <typename T>
void SLL<T>::push(T val){
    NodoSLL<T> *nova = new NodoSLL<T>(val, this->first);
    this->first = nova;
}

template <typename T>
void SLL<T>::append(T val){
    NodoSLL<T> *novo = new NodoSLL<T>(val, nullptr);
    if(this->first){
        NodoSLL<T> *aux = this->first;
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(novo);
    }
    else{
        this->first = novo;
    }
}

template <typename T>
int SLL<T>::remove(int pos){
    int temp;
    if(pos < 0 || pos >= this->longitud()){
        cout << "Posición fuera del rango" << endl;
        return 0;
    }
    else if(!pos){
        NodoSLL<T> *aux = this->first;
        this->first = aux->getNext();
        temp = aux->getDato();
        delete aux;
        return temp;
    }
    else{
        NodoSLL<T> *aux = this->first;
        NodoSLL<T> *prev = nullptr;
        for(int i=0; i<pos; i++){
            prev = aux;
            aux = aux->getNext();
        }
        prev->setNext(aux->getNext());
        temp = aux->getDato();
        delete aux;
    }
    return temp;
}

template <typename T>
void SLL<T>::mostrar(){
    NodoSLL<T> *aux = this->first;
    while(aux != nullptr){
        cout << aux->getDato() << endl;
        aux = aux->getNext();
    }
}

template <typename T>
void SLL<T>::ordenarRapido(int asc) {
    NodoSLL<T>* final = first;
    while (final && final->getNext() != nullptr) {
        final = final->getNext();
    }
    solveQS(first, final, asc);
}

template <typename T>
NodoSLL<T>* SLL<T>::qs(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc) {
    NodoSLL<T>* pIndex; NodoSLL<T>* act;
    T pivot = final->getDato();
    pIndex = act = inicio;

    while (act != final) {
        if ((asc && act->getDato() < pivot) || (!asc && act->getDato() > pivot)) {
            T temp = pIndex->getDato();
            pIndex->setDato(act->getDato());
            act->setDato(temp);
            pIndex = pIndex->getNext();
        }
        act = act->getNext();
    }
    T temp = pIndex->getDato();
    pIndex->setDato(final->getDato());
    final->setDato(temp);
    return pIndex;
}

template <typename T>
void SLL<T>::solveQS(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc) {
    if (inicio != final && inicio && final && inicio != final->getNext()) {
        NodoSLL<T>* pivot = qs(inicio, final, asc);
        NodoSLL<T>* temp = inicio;
        while (temp && temp->getNext() != pivot) {
            temp = temp->getNext();
        }
        if (temp) {
            solveQS(inicio, temp, asc);
        }
        solveQS(pivot->getNext(), final, asc);
    }
}

template <typename T>
SLL<T>::SLL(){
    this->first = nullptr;
}

template <typename T>
SLL<T>::~SLL(){
    NodoSLL<T>* aux = first;
    NodoSLL<T>* nextNode;
    while (aux != nullptr){
        nextNode = aux->getNext();
        delete aux;
        aux = nextNode;
    }
}

#endif
