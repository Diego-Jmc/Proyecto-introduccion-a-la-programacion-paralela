#pragma once
#include "TaskFileManager.h"
#include <limits>
#include "Contact.h"

const std::string TASK_FILE_NAME = "tasks.txt";
const std::string TASK_FILE_100 = "100_tasks.txt";

class Menu
{
private:
	DoublyLinkedList<Task>* list;
	DoublyLinkedList<Contact >* contacts;
	TaskFileManager *fm;
	void println(string);
	void createTask();
	void removeTaskByName(string taskname);
	Date *createDate();
	void show();
	template<typename T>
	T input();
	void saveOnDisk();
	void removeTask();
	void modifyTask();
	void editTaskByName(std::string);
	void contactsMenu();
	void showAllContacts();
	void addContact();
	void assingTask();
	void showContactTasks();

public:
	Menu();
	void start();

};


