#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    ~Date() {}

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    bool isLeapYear() {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    bool isValid() {
        if (year < 1 && (month < 1 || month > 12) && (day < 1 || day > 31)) {
            return false;
        }
        else {
            if (month == 2) {
                if (isLeapYear()) {
                    return day <= 29;
                }
                else {
                    return day <= 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                return day <= 30;
            }
            else {
                return day <= 31;
            }
        }
    }

    void PrintFormat1() {
        cout << day << "." << month << "." << (year % 100);
    }

    void PrintFormat2() {
        cout << day << "/" << month << "/" << year;
    }

    void PrintFormat3() {
        string monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        cout << monthNames[month - 1] << "-" << day << "-" << year;
    }
};