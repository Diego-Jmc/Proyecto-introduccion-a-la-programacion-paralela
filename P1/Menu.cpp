#include "Menu.h"



Menu::Menu() {
	this->fm = new TaskFileManager("tasks.txt");
	list = fm->load();
}

void Menu::println(string text) {
	std::cout << text << std::endl;
}

void Menu::show() {
	std::cout<< this->list->toString() << std::endl;
}

Date* Menu::createDate() {
	int day, month, year;

	println("Fecha");
	println("dia");
	std::cin >> day;
	println("mes");
	std::cin >> month;
	println("annio");
	std::cin >> year;

	try {
		return new Date(day, month, year);
	}
	catch (std::runtime_error &e) {
		throw std::runtime_error("No se pudo crear la fecha , formato incorrecto");
	}

}

void Menu::removeTaskByName(string taskname) {

}

void Menu::createTask() {

	try {
		string name, description;
		bool done = false;
		println("nombre");
		std::cin >> name;
		println("Descripcion");
		std::cin >> description;
		Date* date = createDate();
		list->push(new Task(name, description, date, done));
	}
	catch (std::runtime_error& e) {
		println("Error al crear la tarea, formato incorrecto: "  );
	}





}

void Menu::start() {

	bool onUse = true;

	while (onUse) {

		println("(1) Mostrar tareas");
		println("(2) Agregar tarea");
		println("(3) Eliminar tarea");
		println("(4) Modificar tarea");
		println("(5) Guardar en disco");
		println("(6) Salir");
		int opc;

		std::cin >> opc;

		switch (opc)
		{
		case 1:
			show();
			break;
		case 2:
			createTask();
			break;
		case 3:

		case 6:
			onUse = false;
			break;
		default:
			println("Opcion invalida");
			break;
		}

	}

}
