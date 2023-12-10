#pragma once
#include "Address.h"

class Human {
private:
    string name;
    string surname;
    int age;
    string gender;
    Address address;

public:
    Human(string name = "", string surname = "", int age = 0, string gender = "", Address address = Address()) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->gender = gender;
        this->address = address;
    }

    ~Human() {}

    string getName() { return name; }
    void setName(string newName) { name = newName; }

    string getSurname() { return surname; }
    void setSurname(string newSurname) { surname = newSurname; }

    int getAge() { return age; }
    void setAge(int newAge) { age = newAge; }

    string getGender() { return gender; }
    void setGender(string newGender) { gender = newGender; }

    Address getAddress() { return address; }
    void setAddress(Address newAddress) { address = newAddress; }

    virtual void printInfo() {  // віртуальний метод
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: "; address.printAddress();
    }
};