#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Nodo{
    T data;
    Nodo* next;

    Nodo(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack{
private:
    Nodo<T>* topNodo;

public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    T top();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack() : topNodo(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Nodo<T>* newNodo = new Nodo(data);
    newNodo->next = topNodo;
    topNodo = newNodo;
}

template <typename T>
T Stack<T>::pop() {
    Nodo<T>* nodeToDelete = topNodo;
    T data = nodeToDelete->data;
    topNodo = topNodo->next;
    delete nodeToDelete;
    return data;
}

template <typename T>
T Stack<T>::top() {
    return topNodo->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return topNodo == nullptr;
}

#endif