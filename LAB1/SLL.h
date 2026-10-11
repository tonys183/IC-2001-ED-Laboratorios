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

        NodoSLL<T>* nodoIndex(NodoSLL<T>* first, int pos);
        NodoSLL<T>* qs(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc);
        int maxi(NodoSLL<T>* first, int n);
        void solveQS(NodoSLL<T>* inicio, NodoSLL<T>* final, int asc);
        void recLista(NodoSLL<T>** conts, int asc);
        void count(NodoSLL<T>* first, int n, int exp, int max, int asc);

    public:
        int longitud();
        void insertarPosicion(int pos, T val);
        void push(T val);
        void append(T val);
        int remove(int pos);
        void mostrar();
        void barajar();
        void ordenarRapido(int asc);
        void ordenarRadix(int asc);
        
        SLL();
        ~SLL();
};


template <typename T>
NodoSLL<T>* SLL<T>::nodoIndex(NodoSLL<T>* first, int pos) {
    NodoSLL<T>* aux = first;
    for (int i=0; i<pos && aux!=nullptr; i++) {
        aux = aux->getNext();
    }
    return aux;
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
int SLL<T>::maxi(NodoSLL<T>* first, int n){
    int max = first->getDato();
    for (int i=1; i<n; i++){
        if (first->getDato() > max) {
            max = first->getDato();
        }
        first = first->getNext();
    }
    return max;
}

template <typename T>
void SLL<T>::recLista(NodoSLL<T>** conts, int asc){
    NodoSLL<T>* head = nullptr;
    NodoSLL<T>* tail = nullptr;
    int start = asc ? 0 : 9; int end = asc ? 10 : -1; int jmp = asc ? 1 : -1;

    for (int i=start; i!=end; i+=jmp) {
        if (conts[i] != nullptr) {
            if (head == nullptr) {
                head = conts[i];
                tail = conts[i];
            } else {
                tail->setNext(conts[i]);
                tail = conts[i];
            }
        }
    }
    first = head;
    this->first = first;
}

template <typename T>
void SLL<T>::count(NodoSLL<T>* first, int n, int exp, int max, int asc) {
    NodoSLL<T>** conts = new NodoSLL<T>*[10];
    for (int i=0; i<10; i++) conts[i] = nullptr;

    NodoSLL<T>* aux = first;
    while (aux != nullptr) {
        int dig = (aux->getDato() / exp) % 10;
        NodoSLL<T>* next = aux->getNext();

        if (conts[dig] == nullptr) {
            conts[dig] = aux;
        } else {
            NodoSLL<T>* tail = conts[dig];
            while (tail->getNext() != nullptr) {
                tail = tail->getNext();
            }
            tail->setNext(aux);
        }
        aux->setNext(nullptr);
        aux = next;
    }
    recLista(conts, asc);
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
        cout << aux->getDato() << " ";
        aux = aux->getNext();
    }
    cout << endl;
}

template <typename T>
void SLL<T>::barajar() {
    unsigned long seed = (unsigned long)(time(NULL));
    unsigned long randVal = (1664525 * seed + 1013904223) % (1000000007);
    int n = longitud();

    NodoSLL<T>** nodos = new NodoSLL<T>*[n];
    NodoSLL<T>* aux = first;

    for (int i=0; i<n-1; i++) {
        int j = randVal % (n-i);
        NodoSLL<T>* randNodo = nodoIndex(first, i+j);
        T temp = aux->getDato();
        aux->setDato(randNodo->getDato());
        randNodo->setDato(temp);
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
void SLL<T>::ordenarRadix(int asc){
    int n = longitud();
    int max = maxi(first, n);
    
    for (int exp=1; max/exp>0; exp*=10){
        count(first,n,exp,max,asc);
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
