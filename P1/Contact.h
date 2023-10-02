#pragma once
#include "DoublyLinkedList.h"
#include "Task.h"

using namespace std;

class Contact
{
private:
	string name;
	DoublyLinkedList<Task> *tasks;

public:
	Contact(string);
	~Contact();
	string getName();
	void setName(string);
	void addTask(Task *);
	string getTaskContact();
	friend ostream& operator<<(ostream& os, const Contact& contact)
	{
		os << "Contact Name: " << contact.name << endl;
		return os;
	}
};

