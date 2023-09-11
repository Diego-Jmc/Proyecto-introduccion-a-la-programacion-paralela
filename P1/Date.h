#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Date {

private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day);

    Date();

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    static Date* parseDate(const std::string dateStr);

};