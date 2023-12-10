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

        if (listStudents.size() <= maxStudents) {       // перевірка масиву на допустиму кількість студентів
            for (Student *student : listStudents) {
                if (!student->getCoursework().getTitle().empty() &&         // перевірка студентів, чи кожен записан на здачу курсової роботи
                    !student->getCoursework().getDescription().empty() &&
                    !student->getCoursework().getDeliveryDate().empty()) 
                {
                    if (student == listStudents[listStudents.size()-1]) {
                        this->listStudents = listStudents;
                        numberStudents = listStudents.size();
                    }
                }
                else {
                    cout << "Not all students are registered to submit coursework." << endl << endl;
                    break;
                }
            }
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
        if (numberStudents < maxStudents) {         // перевірка, чи є місце для студента
            if (!student->getCoursework().getTitle().empty() &&
                !student->getCoursework().getDescription().empty() &&
                !student->getCoursework().getDeliveryDate().empty())
            {
                listStudents.push_back(student);
                numberStudents++;
            }
            else {
                cout << "Student is not registered to submit a coursework." << endl << endl;
            }
        }
        else {
            cout << "Maximum student limit reached." << endl << endl;
        }
    }

    void deleteStudent(Student *student) {
        listStudents.erase(remove(listStudents.begin(), listStudents.end(), student), listStudents.end());  // erase–remove idiom
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
        cout << "Maximum student limit: " << maxStudents << endl << endl;
    }
};