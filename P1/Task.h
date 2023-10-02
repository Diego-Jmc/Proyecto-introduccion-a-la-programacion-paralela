#pragma once

#include "Date.h"
using std::string;

class Task {

private:
    string name;
    string description;
    Date* dueDate;
    bool done;
public:
    Task(const string& name, const string& description, Date* dueDate, bool done);

    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "Name: " << task.getName() << std::endl;
        os << "Description: " << task.getDescription() << std::endl;
        os << "Due date: " << *(task.getDueDate()) << std::endl;
        os << "Completed : " << (task.isDone() ? "Yes" : "No") << std::endl;
        return os;
    }

    Task();

    virtual ~Task();

    const string& getName() const;

    void setName(const string& name);

    const string& getDescription() const;

    void setDescription(const string& description);

    Date* getDueDate() const;

    void setDueDate(Date* dueDate);

    bool isDone() const;

    void setDone(bool done);
};
