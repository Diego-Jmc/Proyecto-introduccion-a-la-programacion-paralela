#pragma once
#include <iostream>


template<class T>
class Node
{
private:

	T* data;
	Node* next;
	Node* prev;

public:


	Node();
	~Node();
	T* getData() const;
	void setData(T* newData);
	Node* getNext() const;
	void setNext(Node* newNext);
	Node* getPrev() const;
	void setPrev(Node* newPrev);

};

