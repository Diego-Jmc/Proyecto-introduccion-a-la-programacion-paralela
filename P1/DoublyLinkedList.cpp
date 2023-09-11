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
            temp = temp->next;
            delete temp2->data;
            delete temp2;
        }

    }
}

template<class T>
void DoublyLinkedList<T>::push(T* data) {

    auto* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!root) {
        root = newNode;
    }
    else {
        Node<T>* temp = root;

        while (temp->next) {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;

    }

    length++;
}

template<class T>
bool DoublyLinkedList<T>::empty() {
    return length == 0;
}

template<class T>
void DoublyLinkedList<T>::remove(T value) {

    auto* temp = root;

    while (temp) {

        if (temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp->data;
            delete temp;
            return;
        }

        temp = temp->next;
    }

}

template<class T>
std::string DoublyLinkedList<T>::toString() {
    std::stringstream s;

    auto* temp = root;

    while (temp) {

        s << *temp->data << std::endl;
        temp = temp->next;
    }


    return s.str();
}
