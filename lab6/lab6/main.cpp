#include <iostream>
#include <Windows.h>

#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "ListHumans.h"
#include "Date.h"
#include "Palindrome.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Palindrome num1(1011);

    if (num1.isPalindrome()) { cout << "Число є паліндромом." << endl; }
    else { cout << "Число не є паліндромом." << endl; }

    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    
    Address address1("Country1", "City1");
    Address address2("Country2", "City2");
    Coursework coursework1("Title1", "Description1", "Delivery date1");
    Coursework coursework2("Title2", "Description2", "Delivery date2");

    Student student1("Name1", "Surname1", 18, "Male", address1, coursework1, 2000.0, "320");
    Student student2("Name2", "Surname2", 19, "Female", address2, coursework2, 2500.0, "148");
    Student student3("Name3", "Surname3", 19, "Female", address2, coursework2, 2500.0, "148");
    Student student4("Name4", "Surname4", 19, "Female", address2, coursework2, 2500.0, "148");
    Student student5("Name5", "Surname5", 19, "Female", address2, coursework2, 2500.0, "148");
    Student student6("Name6", "Surname6", 19, "Female", address2, coursework2, 2500.0, "148");

    Teacher teacher1("Name1", "Surname1", 26, "Female", address1, 8000, { &student1, &student2, &student3 });
    Teacher teacher2("Name2", "Surname2", 35, "Male", address2, 11000);

    ListHumans listHumans1;

    listHumans1.addHuman(&student1);
    listHumans1.addHuman(&teacher1);
    listHumans1.addHuman(&student2);
    listHumans1.addHuman(&teacher2);

    teacher1.addStudent(&student1);
    teacher1.addStudent(&student1);
    teacher1.addStudent(&student1);
    //teacher1.deleteStudent(&student1);
    teacher1.printInfo();
    //teacher1.printStudents();

    //listHumans1.printHumans();

    double averageAge = (student1.getAge() + student2.getAge()) / 2.0;
    double totalScholarship = student1.getScholarship() + student2.getScholarship();

    cout << "Average age: " + to_string(averageAge) << endl;
    cout << "Total scholarship: " + to_string(totalScholarship) << endl;

    cout << "---------------------------------------------------------------------------------------------------------------" << endl;

    Date date(31, 10, 2023);

    if (date.isValid()) {
        cout << "The date is correct" << endl;

        if (date.isLeapYear()) {
            cout << "The year is a leap year" << endl;
        }
        else {
            cout << "The year is NOT a leap year" << endl;
        }
    }
    else {
        cout << "The date is incorrect" << endl;
    }
    cout << endl;

    date.PrintFormat1(); cout << endl;
    date.PrintFormat2(); cout << endl;
    date.PrintFormat3(); cout << endl;

    return 0;
}