#ifndef TRIE31_H
#define TRIE31_H

#include <bits/stdc++.h>
#include "STACK.h"
using namespace std;

struct vertex {
    int num;
    bool exist;
    unsigned int count;
    vector<vertex*> child;
    vertex(int d) : num(d), exist(false), count(0) { child.assign(10, nullptr); }
};

class Trie {
private:
    vertex* root;
    void clear(vertex* node);

public:
    Trie();
    void insert(string numb);
    int countPfix();
    void clear();
};

Trie::Trie() : root(new vertex(-1)) {}

void Trie::insert(string numb) {
    vertex* cur = root;

    for (int i = 0; i < (int)numb.size(); ++i) {
      int dig = numb[i] - '0';
      if (cur->child[dig] == nullptr) {
          cur->child[dig] = new vertex(dig);
      }
      cur->count++;
      cur = cur->child[dig];

    }
    cur->exist = true;
}

int Trie::countPfix() {
    int count = 0;
    stack<vertex*> pila;
    pila.push(root);

    while (!pila.empty()) {
        vertex* node = pila.top();
        pila.pop();

        if (node->exist) count += node->count;

        for (vertex* child : node->child) {
            if (child) {
                pila.push(child);
            }
        }
    }
    return count;
}

#endif