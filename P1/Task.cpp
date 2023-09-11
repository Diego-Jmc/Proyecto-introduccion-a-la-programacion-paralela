#include "Task.h"


Task::Task(const string& name, const string& description, Date* dueDate, bool done) : name(name),
description(description),
dueDate(dueDate), done(done) {}

Task::Task() {}

Task::~Task() {
    delete dueDate;
}


const string& Task::getName() const {
    return name;
}

void Task::setName(const string& name) {
    Task::name = name;
}

const string& Task::getDescription() const {
    return description;
}

void Task::setDescription(const string& description) {
    Task::description = description;
}

Date* Task::getDueDate() const {
    return dueDate;
}

void Task::setDueDate(Date* dueDate) {
    Task::dueDate = dueDate;
}

bool Task::isDone() const {
    return done;
}

void Task::setDone(bool done) {
    Task::done = done;
}