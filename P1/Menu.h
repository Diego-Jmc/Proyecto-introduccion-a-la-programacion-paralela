#pragma once
#include "TaskFileManager.h"

class Menu
{
private:
	DoublyLinkedList<Task>* list;
	TaskFileManager *fm;
	void println(string);
	void createTask();
	void removeTaskByName(string taskname);
	Date *createDate();
	void show();
public:
	Menu();
	void start();

};

