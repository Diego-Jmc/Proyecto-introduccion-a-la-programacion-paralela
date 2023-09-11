#pragma once
#include <iostream>
#include <sstream>

template<class T>
struct Node {
    Node* next;
    Node* prev;
    T* data;
};

template<class T>
class DoublyLinkedList {

private:
    Node<T>* root;
    int length;

public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    void push(T* data);
    bool empty();
    void remove(T atribbute); // delete by unique value
    std::string toString();
};
