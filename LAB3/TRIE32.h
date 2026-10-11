#ifndef TRIE32_H
#define TRIE32_H

#include <bits/stdc++.h>
using namespace std;

struct vertex {
    char alphabet;
    bool exist;
    bool lng;
    vector<vertex*> child;
    vertex(char a) : alphabet(a), exist(false), lng(false) { child.assign(26, nullptr); }
};

class Trie {
private:
    vertex* root;

    void clear(vertex* node);
    void answ(vertex* node, string& ans);

public:
    Trie();
    void insert(string word, bool lng);
    bool startsWith(string prefix);
    string imprenta(string& ans);
    void clear();
};

Trie::Trie() : root(new vertex('!')) {}

void Trie::insert(string word, bool lng) {
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == nullptr)
        cur->child[alphaNum] = new vertex(word[i]);
        cur = cur->child[alphaNum];
        cur->lng = lng;
    }
    cur->exist = true;
    cur->lng = lng;
}

string Trie::imprenta(string& ans) {
    answ(root, ans);
    return ans;
}

void Trie::answ(vertex* nodo, string& ans) {
    if (nodo->exist) ans += "P";
    vertex* temp=nullptr;
    for (int i = 0; i < 26; i++) {
        if (nodo->child[i]) {
            if (nodo->child[i]->lng) {
                temp = nodo->child[i];
            } else {
                ans += nodo->child[i]->alphabet;
                answ(nodo->child[i], ans);
                ans += "-";
            }
        }
    }
    if (temp) {
        ans += temp->alphabet;
        answ(temp, ans);
    }
}

#endif
