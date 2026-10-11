#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue{
private:
    Node<T>* frontNode;
    Node<T>* backNode;

public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    T front();
    T back();
    bool isEmpty();
};

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), backNode(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node(data);
    if (isEmpty()) frontNode = backNode = newNode;
    else {
        backNode->next = newNode;
        backNode = newNode;
    }
}

template <typename T>
T Queue<T>::pop() {
    Node<T>* nodeToDelete = frontNode;
    T data = nodeToDelete->data;
    frontNode = frontNode->next;
    delete nodeToDelete;
    if (frontNode == nullptr) backNode = nullptr;
    return data;
}

template <typename T>
T Queue<T>::front() {
    return frontNode->data;
}

template <typename T>
T Queue<T>::back() {
    return backNode->data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return frontNode == nullptr;
}

#endif