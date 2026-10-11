#ifndef TRIE30_H
#define TRIE30_H

#include <bits/stdc++.h>
using namespace std;

struct vertex {
    char alphabet;
    bool exist;
    int mask;
    bool pot2;
    vector<vertex*> child;
    vertex(char a) : alphabet(a), exist(false), mask(0), pot2(false){ child.assign(26, nullptr); }
};

class Trie {
private:
    vertex* root;

    void clear(vertex* node);

public:
    Trie();
    ~Trie();
    void insert(string word, int profsID);
    bool search(string word);
    bool startsWith(string prefix);
    int getMask(string prefix);
    bool esPot2(string prefix);
    void clear();
};

Trie::Trie() : root(new vertex('!')) {}

Trie::~Trie() {
    clear(root);
}

void Trie::insert(string word, int profsID) {
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == nullptr)
        cur->child[alphaNum] = new vertex(word[i]);
        cur = cur->child[alphaNum];
        cur->mask |= (1 << profsID);
        cur->pot2 = (cur->mask & (cur->mask - 1)) == 0;
    }
    cur->exist = true;
}

bool Trie::search(string word) {
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == nullptr)
        return false;
      cur = cur->child[alphaNum];
    }
    return cur->exist; 
}

bool Trie::startsWith(string prefix) {
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      int alphaNum = prefix[i]-'a';
      if (cur->child[alphaNum] == nullptr)
        return false;
      cur = cur->child[alphaNum];
    }
    return cur->mask != 0; 
}

int Trie::getMask(string prefix) {
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
        int alphaNum = prefix[i] - 'a';
        if (cur->child[alphaNum] == nullptr)
            return 0;
        cur = cur->child[alphaNum];
    }
    return cur->mask;
}

bool Trie::esPot2(string prefix) {
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
        int alphaNum = prefix[i] - 'a';
        if (cur->child[alphaNum] == nullptr)
            return false;
        cur = cur->child[alphaNum];
    }
    return cur->pot2;
}

void Trie::clear() {
    clear(root);
    root = new vertex('!');
}

void Trie::clear(vertex* nodo) {
    if (nodo == nullptr) return;
    for (vertex* child : nodo->child) {
        clear(child);
    }
    delete nodo;
}

#endif