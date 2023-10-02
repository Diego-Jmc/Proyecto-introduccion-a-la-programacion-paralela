#include "Menu.h"

Menu::Menu() {
    this->fm = new TaskFileManager(TASK_FILE_100);
    list = fm->load();
    this->contacts = new DoublyLinkedList<Contact>();
}


void Menu::saveOnDisk()
{
    try {
        fm->saveAll(list);
        println("tasks saved on disk");
    }
    catch (std::exception& e) {
        println("Error trying to save tasks on disk");
    }


}


void Menu::assingTask() {
    println("Write the task name");
    string taskname = input<string>();
    auto* task = list->getByName(taskname);

    if (task) {
        println("Write the contact name");
        string contactName = input<string>();
            auto* contact = contacts->getByName(contactName);

            if (contact) {
                contact->addTask(task);
            }
            else {
                println("The contact does not exist");
            }


    }
    else {
        println("The task does not exist");
    }
}


void Menu::showAllContacts() {
    println(contacts->toString());
}

void Menu::showContactTasks() {
    println("Write the contact name");
    string contactName = input<string>();
    auto* contact = contacts->getByName(contactName);

    if (contact) {
        println(contact->getTaskContact());
    }
    else {
        println("The contact does not exist");
    }
}

void Menu::addContact() {
    string contactName;
    println("Write the name of the contact");
    contactName = input<string>();
    Contact *c = new Contact(contactName);
    contacts->push(c);
    println("Contact added");
}

void Menu::removeTask()
{
    println("Type the task name");
    std::string task_name = input<std::string>();
    removeTaskByName(task_name);
}

void Menu::editTaskByName(std::string taskname) {
    Task* t = list->getByName(taskname);

    if (t != nullptr) {

        try {
            println("Type 1 to mark the task as done , 0 to mark the task as uncomplete");
            bool isDone;
            std::cin >> isDone;
            t->setDone(isDone);
            if (std::cin.fail()) {
                throw std::ios_base::failure("Incorrect year format");
            }
        }
        catch (const std::ios_base::failure& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Error trying to create date , invalid format");
        }
    

    }
    else {
        println("Invalid task name");

    }



}

void Menu::contactsMenu()
{
    bool onUse = true;
    int opc;

    while (onUse) {
        println("(1) Show contacts");
        println("(2) Show tasks from contact");
        println("(3) Add contact");
        println("(4) Assign task to contact");
        println("(5) Exit");
        std::cin >> opc;

        switch (opc) {
        case 1:
            showAllContacts();
            break;
        case 2:
            showContactTasks();
            break;
        case 3:
            addContact();
            break;
        case 4:
            assingTask();
            break;
        case 5:
            onUse = false;
            break;
        default:
            println("Invalid option");
        }
  

    }

}

void Menu::modifyTask()
{
    println("Type the task name");
    std::string task_name = input<std::string>();
    editTaskByName(task_name);

}



void Menu::println(string text) {
    std::cout << text << std::endl;
}

void Menu::show() {
    std::cout << this->list->toString() << std::endl;
}

template<typename T>
T Menu::input() {
    T input;
    cin.ignore();
    getline(std::cin, input);
    return input;
}

void Menu::removeTaskByName(string taskname) {
    try {
        Task* taskToDelete = list->getByName(taskname);

        if (taskToDelete != nullptr) {
            list->remove(taskToDelete);
        }
        else {
            println("The inserted task do not exist!");

        }
    }
    catch (std::exception &e) {
        println("Error trying to delete task");
    }

}



Date* Menu::createDate() {
    int day, month, year;

    try {
        println("Date");
        println("Day");
        std::cin >> day;
        if (std::cin.fail()) {
            throw std::ios_base::failure("Incorrect day format");
        }

        println("Month");
        std::cin >> month;
        if (std::cin.fail()) {
            throw std::ios_base::failure("Incorrect month format");
        }

        println("Year");
        std::cin >> year;
        if (std::cin.fail()) {
            throw std::ios_base::failure("Incorrect year format");
        }

        return new Date(year,month,day);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    catch (const std::ios_base::failure& e) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        throw std::runtime_error("Error trying to create date , invalid format");
    }

}


void Menu::createTask() {

    try {
        string name, description;
        bool done = false;

        println("Type the name:");
        name = input<std::string>();
        println("Type description:");
        description = input<std::string>();

        Date* date = createDate();
        list->push(new Task(name, description, date, done));

    }
    catch (std::runtime_error& e) {
        println("Error trying to create task ,date invalid format ");
    }
    catch (const std::ios_base::failure& e) {
        println("Error trying to create task , invalid format ");

    }

}

void Menu::start() {

    bool onUse = true;

    while (onUse) {

        try {
            println("(1) Show taks");
            println("(2) Add task");
            println("(3) Delete task");
            println("(4) Modify task");
            println("(5) Save on disk");
            println("(6) Contacts");
            println("(7) Exit");
            int opc;

            if (std::cin.fail()) {
                throw std::ios_base::failure("Bad format");
            }

            std::cin >> opc;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (opc)
            {
            case 1:
                show();
                break;
            case 2:
                createTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                modifyTask();
                break;
            case 5:
                saveOnDisk();
                break;
            case 6:
                contactsMenu();
                break;
            case 7:
                onUse = false;
                break;
            default:
                println("Invalid option");
                break;
            }
        }
        catch (std::runtime_error& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            println("Error , use the correct format ");

        }
    }

}
