#pragma once
#include <iostream>
#include <sstream>
#include "Node.cpp"

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
    bool remove(T* atribbute);
    std::string toString();
    bool contains(T*);
    int size();
    Node<T>* getRoot();
    T* getByName(std::string name);
};


