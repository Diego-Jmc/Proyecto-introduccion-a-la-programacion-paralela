#include "TaskFileManager.h"


TaskFileManager::TaskFileManager(string _filename) {
	this->filename = _filename;
}


void TaskFileManager::save(Task *task) {

	std::ofstream task_file(filename, std::ios::app);

	if (task_file.is_open()) {

		task_file << task->getName() << std::endl;

		task_file << task->getDescription() << std::endl;

		task_file << * task->getDueDate() << std::endl;

		task_file << task->isDone() << std::endl;

	}

	task_file.close();


}

DoublyLinkedList<Task>* TaskFileManager::load() {
    DoublyLinkedList<Task>* taskList = new DoublyLinkedList<Task>();

    std::ifstream archivo(filename); 

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de tareas." << std::endl;
        return taskList; 
    }

    std::string nombre;
    std::string descripcion;
    std::string fechaVencimientoStr;
    std::string estadoStr;

    while (std::getline(archivo, nombre)) {

        std::getline(archivo, descripcion);
        std::getline(archivo, fechaVencimientoStr);
        std::getline(archivo, estadoStr);

        Date* fechaVencimiento = Date::parseDate(fechaVencimientoStr);
        bool estado = (estadoStr == "1");

        Task* tarea = new Task(nombre, descripcion, fechaVencimiento, estado);


        taskList->push(tarea);
    }

    archivo.close(); 

    return taskList;
}



void TaskFileManager::saveAll(DoublyLinkedList<Task>* tasks)
{
    auto* root = tasks->getRoot();

    std::ofstream task_file(filename);


    std::stringstream s;

    while (root) {

        s << root->getData()->getName() << std::endl;
        s << root->getData()->getDescription() << std::endl;
        s << *root->getData()->getDueDate() << std::endl;
        s << root->getData()->isDone() << std::endl;

        root = root->getNext();
    }

    if (task_file.is_open()) {
        task_file << s.str();
    }


    task_file.close();

}
