#include "Node.h"

template<class T>
Node<T>::Node() {
    this->next = nullptr;
    this->prev = nullptr;
    this->data = nullptr;
}

template<class T>
Node<T>::~Node()
{
    delete data;
}


template<class T>
T* Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(T* newData)
{
    data = newData;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}

template<class T>
void Node<T>::setNext(Node* newNext)
{
    next = newNext;
}

template<class T>
Node<T>* Node<T>::getPrev() const
{
    return prev;
}

template<class T>
void Node<T>::setPrev(Node* newPrev)
{
    prev = newPrev;
}

