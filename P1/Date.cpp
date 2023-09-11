#include "Date.h"

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

Date::Date() {
    this->year = 0;
    this->month = 0;
    this->day = 0;
}

Date* Date::parseDate(std::string dateStr) {
    try {
        std::string save;
        std::stringstream s;
        s << dateStr;

        int day, month, year;

        std::getline(s, save, '/');
        day = std::stoi(save);
        std::getline(s, save, '/');
        month = std::stoi(save);
        std::getline(s, save, '/');
        year = std::stoi(save);

        return new Date(day, month, year);
    }
    catch (const std::runtime_error& e) {
        throw std::runtime_error("Error de conversión: No se pudo convertir la cadena en un número entero válido.");
    }
}


int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}
