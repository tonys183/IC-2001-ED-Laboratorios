#ifndef FENWICK
#define FENWICK

#include <bits/stdc++.h>
using namespace std;

struct IntegerAddition {
    unsigned long long int apply(int a, int b) { return a + b; }
    unsigned long long int undo(int c, int b) { return c - b; }
};

template <typename T>
class FenwickTree {
private:
    vector<T> tree;
    IntegerAddition f;

public:
    FenwickTree(vector<T>& ar);
    T query(int i);
    T query(int i, int j);
    T valueAt(int i);
    void apply(int i, T k);
    void update(int i, T value);
};

template <typename T>
FenwickTree<T>::FenwickTree(vector<T>& ar){
    tree = ar;
    int size = tree.size();

    for (int i = 1; i < size; i++) {
        int p = i + (i & -i);
        if (p < size) {
            tree[p] = f.apply(tree[p], tree[i]);
        }
    }
}

template <typename T>
T FenwickTree<T>::query(int i){
    T q = 0;
    while (i > 0) {
        q = f.apply(q, tree[i]);
        i -= i & -i;
    }
    return q;
}

template <typename T>
T FenwickTree<T>::query(int i, int j){
    if (i > 1) {
        return f.undo(query(j), query(i - 1));
    } else {
        return query(j);
    }
}

template <typename T>
T FenwickTree<T>::valueAt(int i){
    return f.undo(query(i), query(i - 1));
}

template <typename T>
void FenwickTree<T>::apply(int i, T k){
    int size = tree.size();
    while (i < size) {
        tree[i] = f.apply(tree[i], k);
        i += i & -i;
    }
}

template <typename T>
void FenwickTree<T>::update(int i, T value){
    T orig = valueAt(i);
    apply(i, f.undo(value, orig));
}

#endif
