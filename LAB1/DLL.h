#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;

template <typename T>
class NodoDLL {
    private:
        T dato;
        NodoDLL* next;
        NodoDLL* prev;
    public:
        T getDato() {
            return this->dato;
        }
        void setDato(T pDato) {
            this->dato = pDato;
        }
        NodoDLL* getNext() {
            return this->next;
        }
        void setNext(NodoDLL* pNext) {
            this->next = pNext;
        }
        NodoDLL* getPrev() {
            return this->prev;
        }
        void setPrev(NodoDLL* pPrev) {
            this->prev = pPrev;
        }
        NodoDLL(T pDato, NodoDLL* pNext = nullptr, NodoDLL* pPrev = nullptr) {
            this->dato = pDato;
            this->next = pNext;
            this->prev = pPrev;
        }
};

template <typename T>
class DLL {
private:
    NodoDLL<T>* first;
    NodoDLL<T>* tail;

    NodoDLL<T>* mitad(NodoDLL<T>* head);
    NodoDLL<T>* merge(NodoDLL<T>* left, NodoDLL<T>* right, int asc);
    NodoDLL<T>* mergeSort(NodoDLL<T>* head, int asc);

public:
    int longitud();
    void insertarPosicion(int pos, T val);
    void push(T val);
    void append(T val);
    int remove(int pos);
    void mostrar();
    void concatenar(DLL &otra);
    T maxmin(int asc);
    void ordenarHeap(int asc);

    DLL();
    ~DLL();
};

template <typename T>
DLL<T>::DLL() : first(nullptr), tail(nullptr) {}

template <typename T>
DLL<T>::~DLL() {
    NodoDLL<T>* aux = first;
    NodoDLL<T>* nextNode;
    while (aux) {
        nextNode = aux->getNext();
        delete aux;
        aux = nextNode;
    }
}


template <typename T>
int DLL<T>::longitud() {
    NodoDLL<T>* aux = this->first;
    int cont = 0;
    while (aux) {
        cont++;
        aux = aux->getNext();
    }
    return cont;
}

template <typename T>
void DLL<T>::insertarPosicion(int pos, T val) {
    if (pos < 0 || pos > this->longitud()) {
        append(val);
    } else if (!pos) {
        push(val);
    } else {
        NodoDLL<T>* aux = this->first;
        NodoDLL<T>* prev;
        for (int i=0; i<pos; i++) {
            prev = aux;
            aux = aux->getNext();
        }
        NodoDLL<T>* nova = new NodoDLL<T>(val, aux, prev);
        prev->setNext(nova);
        if (aux) aux->setPrev(nova);
        if (!nova->getNext()) tail = nova;
    }
}

template <typename T>
void DLL<T>::push(T val) {
    NodoDLL<T>* nova = new NodoDLL<T>(val, first, nullptr);
    if (first) this->first->setPrev(nova);
    else tail = nova;
    first = nova;
}

template <typename T>
void DLL<T>::append(T val) {
    NodoDLL<T>* nova = new NodoDLL<T>(val);
    if (first) {
        tail->setNext(nova);
        nova->setPrev(tail);
        tail = nova;
    } else {
        first = tail = nova;
    }
}

template <typename T>
int DLL<T>::remove(int pos) {
    if (pos < 0 || pos >= this->longitud()) {
        cout << "Posición fuera del rango" << endl;
        return 0;
    } else if (!pos) {
        NodoDLL<T>* aux = first;
        first = first->getNext();
        if (first) first->setPrev(nullptr);
        if (!first) tail = nullptr;
        int temp = aux->getDato(); delete aux; return temp;
    } else {
        NodoDLL<T>* aux = this->first;
        NodoDLL<T>* prev;
        for (int i=0; i<pos; i++) {
            prev = aux;
            aux = aux->getNext();
        }
        prev->setNext(aux->getNext());
        if (aux->getNext()) aux->getNext()->setPrev(prev);
        if (!aux->getNext()) tail = prev;
        int temp = aux->getDato(); delete aux;
        return temp;
    }
}

template <typename T>
void DLL<T>::mostrar() {
    NodoDLL<T>* aux = this->first;
    while (aux) {
        cout << aux->getDato() << " ";
        aux = aux->getNext();
    }
    cout << endl;
}

template <typename T>
void DLL<T>::concatenar(DLL& otra) {
    if (!otra.first) return;
    
    if (!first) {
        first = otra.first;
        tail = otra.tail;
    } else {
        tail->setNext(otra.first);
        if (otra.first) otra.first->setPrev(tail);
        tail = otra.tail;
    }
    otra.first = nullptr;
    otra.tail = nullptr;
}

template <typename T>
T DLL<T>::maxmin(int asc) {
    NodoDLL<T>* aux = this->first;
    T min, max;
    min = max = aux->getDato();
    while (aux) {
        if (aux->getDato() > max) {
            max = aux->getDato();
        }
        if (aux->getDato() < min) {
            min = aux->getDato();
        }
        aux = aux->getNext();
    }
    return asc ? min : max;
}

template <typename T>
void DLL<T>::ordenarHeap(int asc) {
    first = mergeSort(first, asc);
    if (!first) tail = nullptr;
    else {
        NodoDLL<T>* aux = first;
        while (aux->getNext()) {
            aux = aux->getNext();
        }
        tail = aux;
    }
}

template <typename T>
NodoDLL<T>* DLL<T>::mitad(NodoDLL<T>* head) {
    if (!head) return nullptr;
    NodoDLL<T>* mid = head;
    NodoDLL<T>* last = head->getNext();
    while (last && last->getNext()) {
        mid = mid->getNext();
        last = last->getNext()->getNext();
    }
    return mid;
}

template <typename T>
NodoDLL<T>* DLL<T>::merge(NodoDLL<T>* left, NodoDLL<T>* right, int asc) {
    if (!left) return right;
    if (!right) return left;
    
    NodoDLL<T>* novaLista = nullptr;
    if ((asc && left->getDato() <= right->getDato()) || (!asc && left->getDato() > right->getDato())) {
        novaLista = left;
        novaLista->setNext(merge(left->getNext(), right, asc));
        if (novaLista->getNext()) novaLista->getNext()->setPrev(novaLista);
    } else {
        novaLista = right;
        novaLista->setNext(merge(left, right->getNext(), asc));
        if (novaLista->getNext()) novaLista->getNext()->setPrev(novaLista);
    }
    return novaLista;
}

template <typename T>
NodoDLL<T>* DLL<T>::mergeSort(NodoDLL<T>* first, int asc) {
    if (!first || !first->getNext()) return first;
    
    NodoDLL<T>* mid = mitad(first);
    NodoDLL<T>* midNext = mid->getNext();
    mid->setNext(nullptr);
    if (midNext) midNext->setPrev(nullptr);
    
    NodoDLL<T>* L = mergeSort(first, asc);
    NodoDLL<T>* R = mergeSort(midNext, asc);
    
    return merge(L, R, asc);
}

#endif