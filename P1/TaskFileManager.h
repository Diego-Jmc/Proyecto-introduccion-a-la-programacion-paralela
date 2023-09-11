#pragma once
#include "Task.h"
#include "DoublyLinkedList.cpp"
#include <fstream>

class TaskFileManager
{

private:
	string filename;
public:
	TaskFileManager(string);
	void save(Task *t);
	DoublyLinkedList<Task>* load();

};

