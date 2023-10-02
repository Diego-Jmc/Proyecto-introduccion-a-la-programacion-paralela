#pragma once
#include "Task.h"
#include <fstream>
#include "DoublyLinkedList.h"

class TaskFileManager
{

private:
	string filename;
public:
	TaskFileManager(string);
	void save(Task *t);
	DoublyLinkedList<Task>* load();
	void saveAll(DoublyLinkedList<Task>* tasks);

};

#include "DoublyLinkedList.cpp"