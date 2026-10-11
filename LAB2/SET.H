#ifndef SET_H
#define SET_H

#include <iostream>
#include "AVL.h"
#include "SLL.h"
using namespace std;

class SET{
  private:
    AVL* avl;
    int size;
    int actuSize=0;

    void preordenMod(NodoAVL* T, SET& result, SET* conj);
    void preorden(NodoAVL* nodo, SLL<string>& lista);
    SET diferencia(SET* conj);
    void clean();
    
  public:
    SET();
    SET(int cap);
    ~SET();
    int estaVacio();
    int cardinalidad();
    int cardinalidadMax();
    bool insertar(string v);
    bool eliminar(string v);
    bool contiene(string v);
    SET intersect(SET* conj);
    SET unionSet(SET* conj);
    SLL<string> elementos();
    void preorderAVL();
    SET getDiferencia(SET* conj);
    void mkClean();
};

SET::SET(){
    avl = new AVL();
}

SET::SET(int cap) : size(cap) {
    avl = new AVL();
}

SET::~SET() {
    delete avl;
}

int SET::estaVacio(){
    return actuSize == 0;
}

int SET::cardinalidad(){
    return actuSize;
}

int SET::cardinalidadMax(){
    if (size >= 0) return size;
    return INT_MAX - 1;
}

bool SET::insertar(string v){
    if (cardinalidad() < cardinalidadMax() && !avl->search(v)) {
        avl->insert(v);
        actuSize++;
        return true;
    }
    return false;
}

bool SET::eliminar(string v){
    if(avl->search(v)){
        avl->remove(v);
        actuSize--;
        return true;
    }
    return false;
}

bool SET::contiene(string v){
    return avl->search(v);
}

SET SET::intersect(SET* conj) {
    SET result;
    preordenMod(avl->getRoot(), result, conj);
    return result;
}

SET SET::unionSet(SET* conj) {
    SET result;
    preordenMod(this->avl->getRoot(), result, this);
    preordenMod(conj->avl->getRoot(), result, conj);
    return result;
}

SLL<string> SET::elementos() {
    SLL<string> lista;
    preorden(avl->getRoot(), lista);
    return lista;
}

SET SET::getDiferencia(SET* conj){
    return diferencia(conj);
}
    
    
void SET::mkClean(){
    clean();
}


void SET::preorden(NodoAVL* nodo, SLL<string>& lista) {
    if (nodo == nullptr) return;

    lista.append(nodo->key);
    preorden(nodo->left, lista);
    preorden(nodo->right, lista);
}

void SET::preordenMod(NodoAVL* T, SET& result, SET* conj) {
    if (T == nullptr) return;
    if (conj->contiene(T->key)) result.insertar(T->key);
    preordenMod(T->left, result, conj);
    preordenMod(T->right, result, conj);
}

SET SET::diferencia(SET* conj) {
    SET unionResult = this->unionSet(conj);
    SET intersectResult = this->intersect(conj);
    SET result;
    
    SLL<string> listaUnion = unionResult.elementos();
    NodoSLL<string>* nodoUnion = listaUnion.getFirst();

    while (nodoUnion != nullptr) {
        if (!intersectResult.contiene(nodoUnion->getDato())) {
            result.insertar(nodoUnion->getDato());
        }
        nodoUnion = nodoUnion->getNext();
    }
    return result;
}

void SET::clean() {
    delete avl;
    avl = new AVL();
}

void SET::preorderAVL(){
    avl->preorder();
}

#endif