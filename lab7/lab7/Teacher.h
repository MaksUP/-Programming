#pragma once
#include <vector>
#include "Human.h"

class Teacher : public Human {
private:
    float salary;
    vector<Student *> listStudents;
    size_t numberStudents = listStudents.size();
    const int maxStudents = 5;

public:
    Teacher(string name = "", string surname = "", int age = 0, string gender = "", Address address = Address(), float salary = 0.0, vector<Student *> listStudents = {}) : Human(name, surname, age, gender, address) {
        this->salary = salary;

        if (listStudents.size() <= maxStudents) {       // перев≥рка масиву на допустиму к≥льк≥сть студент≥в
            this->listStudents = listStudents;
            numberStudents = listStudents.size();
        }
        else {
            cout << "Maximum student limit exceeded." << endl << endl;
        }
    }

    Teacher(Human &human, float &salary, vector<Student *> &listStudents) : Human(human) {
        this->salary = salary;

        if (listStudents.size() <= maxStudents) {
            this->listStudents = listStudents;
            numberStudents = listStudents.size();
        }
        else {
            cout << "Maximum student limit exceeded." << endl << endl;
        }
    }

    ~Teacher() {}

    float getSalary() { return salary; }
    void setSalary(float newSalary) { salary = newSalary; }

    vector<Student *> getListStudents() { return listStudents; }
    void setListStudents(vector<Student *> newListStudents) { listStudents = newListStudents; }

    size_t getNumberStudents() { return numberStudents; }

    int getMaxStudents() { return maxStudents; }

    void addStudent(Student *student) {
        if (numberStudents < maxStudents) {         // перев≥рка, чи Ї м≥сце дл€ студента
            listStudents.push_back(student);
            numberStudents++;
        }
        else {
            cout << "Maximum student limit reached." << endl << endl;
        }
    }

    void deleteStudent(Student *student) {
        listStudents.erase(remove(listStudents.begin(), listStudents.end(), student), listStudents.end());  // eraseЦremove idiom
        numberStudents--;
    }

    void printStudents() {
        for (Student *student : listStudents) {
            student->printInfo();
        };
    }

    void printInfo() override {
        __super::printInfo();
        cout << "Salary: " << salary << endl;
        cout << "Number of students: " << numberStudents << endl;
        cout << "Maximum student limit: " << maxStudents << endl;
    }
};