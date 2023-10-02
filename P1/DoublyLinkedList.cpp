#include "DoublyLinkedList.h"


template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->root = nullptr;
    length = 0;
}


template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

    if (root) {

        auto temp = root;
        Node<T>* temp2;
        while (temp) {
            temp2 = temp;
            temp = temp->getNext();
            delete temp2->getData();
            delete temp2;
        }

    }
}

template<class T>
void DoublyLinkedList<T>::push(T* data) {

    auto* newNode = new Node<T>;
    newNode->setData(data);
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);

    if (!root) {
        root = newNode;
    }
    else {
        Node<T>* temp = root;

        while (temp->getNext()) {
            temp = temp->getNext();
        }
        newNode->setPrev(temp);
        temp->setNext(newNode);

    }

    length++;
}

template<class T>
bool DoublyLinkedList<T>::empty() {
    return length == 0;
}

template<class T>
bool DoublyLinkedList<T>::remove(T* value) {

    auto* temp = root;

    while (temp) {

        if (temp->getData()->getName() == value->getName()) {

            if (temp->getPrev() != nullptr)
                temp->getPrev()->setNext(temp->getNext());


            if (temp->getNext() != nullptr)
                temp->getNext()->setPrev(temp->getPrev());

            delete temp;
            this->length--;
            return true;
        }

        temp = temp->getNext();
    }
    return false;
}

template<class T>
std::string DoublyLinkedList<T>::toString() {
    std::stringstream s;

    auto* temp = root;

    while (temp) {

        s << (*temp->getData()) << std::endl;
        temp = temp->getNext();
    }


    return s.str();
}

template<class T>
bool DoublyLinkedList<T>::contains(T* data) {
    auto* temp = root;

    while (temp) {


        if (temp->getData()->getName() == data->getName())
            return true;

        temp = temp->getNext();
    }

    return false;
}

template<class T>
int DoublyLinkedList<T>::size()
{
    return this->length;
}

template<class T>
Node<T>* DoublyLinkedList<T>::getRoot()
{
    return root;
}

template<class T>
T* DoublyLinkedList<T>::getByName(std::string name)
{
    auto* temp = root;

    while (temp) {


        if (temp->getData()->getName() == name)
            return temp->getData();

        temp = temp->getNext();
    }

    return nullptr;
}



