#pragma once
#include "Human.h"

class Student : public Human {
private:
    float scholarship;
    string group;

public:
    Student(string name = "", string surname = "", int age = 0, string gender = "", Address address = Address(), float scholarship = 0.0, string group = "") : Human(name, surname, age, gender, address) {
        this->scholarship = scholarship;
        this->group = group;
    }

    Student(Human &human, float &scholarship, string &group) : Human(human) {
        this->scholarship = scholarship;
        this->group = group;
    }

    ~Student() {}

    float getScholarship() { return scholarship; }
    void setScholarship(float newScholarship) { scholarship = newScholarship; }

    string getGroup() { return group; }
    void setGroup(string newGroup) { group = newGroup; }

    void printInfo() override {     // перевизначення віртуального методу
        __super::printInfo();   // виклик методу з базового класу 
        cout << "Scholarship: " << scholarship << endl;
        cout << "Group: " << group << endl;
    }
};