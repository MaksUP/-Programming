#pragma once
#include "Human.h"
#include "Coursework.h"

class Student : public Human {
private:
    float scholarship;
    string group;
    Coursework coursework;

public:
    Student(string name = "", string surname = "", int age = 0, string gender = "", Address address = Address(), Coursework coursework = Coursework(), float scholarship = 0.0, string group = "") : Human(name, surname, age, gender, address) {
        this->scholarship = scholarship;
        this->group = group;
        this->coursework = coursework;
    }

    ~Student() {}

    float getScholarship() { return scholarship; }
    void setScholarship(float newScholarship) { scholarship = newScholarship; }

    string getGroup() { return group; }
    void setGroup(string newGroup) { group = newGroup; }

    Coursework getCoursework() { return coursework; }
    void setCoursework(Coursework newCoursework) { coursework = newCoursework; }

    void printInfo() override {     // перевизначення віртуального методу
        __super::printInfo();   // виклик методу з базового класу 
        cout << "Scholarship: " << scholarship << endl;
        cout << "Group: " << group << endl;
        cout << "Coursework: "; coursework.printCoursework();
        cout << endl;
    }
};