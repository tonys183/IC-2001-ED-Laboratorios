#ifndef AVL_H
#define AVL_H

#include <iostream>
using namespace std;

unsigned int expt(unsigned int n, unsigned int e, int mod){
    if(!e) return 1;
    int res = expt(n,e/2, mod)%mod;
    res *= res % mod;
    if(e%2) res *= n % mod;
    return res % mod;
}

struct NodoAVL {
  NodoAVL* parent;
  NodoAVL* left;
  NodoAVL* right;
  string key;
  int h1;
  int h2;
  int height;
};

class AVL{
  private:
    NodoAVL* root;
    int h(NodoAVL* T) { return T == nullptr ? -1 : T->height; }
    
    unsigned int hashStr(string s, int p, int q);
    NodoAVL* insert(NodoAVL* T, string val);
    void preorder(NodoAVL* T);
    NodoAVL* search(NodoAVL* T, string val);
    string findMin(NodoAVL* T);
    string successor(NodoAVL* T);
    NodoAVL* remove(NodoAVL* T, string val);
    NodoAVL* rotateLeft(NodoAVL* T);
    NodoAVL* rotateRight(NodoAVL* T);
    NodoAVL* rebalance(NodoAVL* T);
    int getHeight(NodoAVL* T);

  public:
    AVL();

    NodoAVL* getRoot();
    void insert(string v);
    void remove(string v);
    void preorder();
    int search(string val);
    string findMin();
};

AVL::AVL() {root = nullptr;}

NodoAVL* AVL::getRoot() { 
  return root;
}

void AVL::insert(string v) {
  root = insert(root, v);
}

void AVL::remove(string v) { 
  root = remove(root, v); 
}

void AVL::preorder() { 
  preorder(root);
  printf("\n");
}

int AVL::search(string val) {
  return search(root, val) != nullptr;
}

string AVL::findMin() { 
  return findMin(root);
}

unsigned int AVL::hashStr(string s, int p, int q){
  unsigned int h=0;
  for(int i=0; s[i]; i++, h%=p){
    h += expt(q, s[i], p);
  }
  return h%p;
}

NodoAVL* AVL::insert(NodoAVL* T, string val){
  int tHash = hashStr(val, 1000000007, 53);
  int t2Hash = hashStr(val, 1000000009, 31);

  if (T == nullptr) {
    T = new NodoAVL;
    T->key = val;
    T->h1 = tHash;
    T->h2 = t2Hash;
    T->parent = T->left = T->right = nullptr;
    T->height = 0;
  }
  else if(T->h1 == tHash && T->h2 == t2Hash){
    return T;
  }
  else if (T->h1 < tHash) {
    T->right = insert(T->right, val);
    T->right->parent = T;
  }
  else {
    T->left = insert(T->left, val);
    T->left->parent = T;
  }
  T = rebalance(T);
  return T;
}

void AVL::preorder(NodoAVL* T) {
  if (T == nullptr) return;
  cout << T->key << endl;
  preorder(T->left);
  preorder(T->right);
}

NodoAVL* AVL::search(NodoAVL* T, string val) {
  int tHash = hashStr(val, 1000000007, 53);
  int t2Hash = hashStr(val, 1000000009, 31);

  if (T == nullptr) return T;
  else if (T->h1 == tHash && T->h2 == t2Hash) return T;
  else if (T->h1 < tHash) return search(T->right, val);
  else return search(T->left, val);
}

string AVL::findMin(NodoAVL* T) {
  if (T == nullptr) return "N/F";
  else if (T->left == nullptr) return T->key;
  else return findMin(T->left);
}

string AVL::successor(NodoAVL* T) {
  if (T->right != nullptr) return findMin(T->right);
  else {
    NodoAVL* par = T->parent;
    NodoAVL* cur = T;
    while ((par != nullptr) && (cur == par->right)) {
      cur = par;
      par = cur->parent;
    }
    return par == nullptr ? "N/F" : par->key;
  }
}

NodoAVL* AVL::remove(NodoAVL* T, string val) {
  if (T == nullptr)  return T;
  int tHash = hashStr(val, 1000000007, 53);
  int t2Hash = hashStr(val, 1000000009, 31);
  
  if (T->h1 == tHash && T->h2 == t2Hash) {
    if (T->left == nullptr && T->right == nullptr) T = nullptr;
    else if (T->left == nullptr && T->right != nullptr) {
      T->right->parent = T->parent;
      T = T->right;
    }
    else if (T->left != nullptr && T->right == nullptr) {
      T->left->parent = T->parent;
      T = T->left;
    }
    else { 
      string successorV = successor(T);
      T->key = successorV;
      T->right = remove(T->right, successorV);
    }
  }
  else if (T->h1 < tHash)
    T->right = remove(T->right, val);
  else
    T->left = remove(T->left, val);

  if (T != nullptr) {
    T = rebalance(T);
  }
  return T;
}

NodoAVL* AVL::rotateLeft(NodoAVL* T) {
  NodoAVL* w = T->right;
  w->parent = T->parent;
  T->parent = w;
  T->right = w->left;
  if (w->left != nullptr) w->left->parent = T;
  w->left = T;

  T->height = max(h(T->left), h(T->right)) + 1;
  w->height = max(h(w->left), h(w->right)) + 1;

  return w;
}

NodoAVL* AVL::rotateRight(NodoAVL* T) {
  NodoAVL* w = T->left;
  w->parent = T->parent;
  T->parent = w;
  T->left = w->right;
  if (w->right != nullptr) w->right->parent = T;
  w->right = T;

  T->height = max(h(T->left), h(T->right)) + 1;
  w->height = max(h(w->left), h(w->right)) + 1;

  return w;
}

NodoAVL* AVL::rebalance(NodoAVL* T) {
    int balance = h(T->left) - h(T->right);
    if (balance == 2) {
        int balance2 = h(T->left->left) - h(T->left->right);
        if (balance2 >= 0) {
            T = rotateRight(T);
        }
        else {
            T->left = rotateLeft(T->left);
            T = rotateRight(T);
        }
    }
    else if (balance == -2) {
        int balance2 = h(T->right->left) - h(T->right->right);
        if (balance2 <= 0)
            T = rotateLeft(T);
        else {
            T->right = rotateRight(T->right);
            T = rotateLeft(T);
        }
    }

    T->height = max(h(T->left), h(T->right)) + 1;
    return T;
}

int AVL::getHeight(NodoAVL* T) {
  if (T == nullptr) return -1;
  else return max(getHeight(T->left), getHeight(T->right)) + 1;
}

#endif