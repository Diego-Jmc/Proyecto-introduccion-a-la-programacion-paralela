#include "Contact.h"


Contact::Contact(string contact) {
	this->name = contact;
	this->tasks = new DoublyLinkedList<Task>();
}

Contact::~Contact() {
	delete tasks;
}

string Contact::getName()
{
	return name;
}

void Contact::setName(string name)
{
	this->name = name;
}

void Contact::addTask(Task* task)
{
	tasks->push(task);
}

string Contact::getTaskContact()
{
	return tasks->toString();
}
