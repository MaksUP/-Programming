#pragma once
#include <string>
using namespace std;

class Address {
private:
    string country;
    string city;

public:
    Address(string country = "", string city = "") {
        this->country = country;
        this->city = city;
    }

    ~Address() {}

    string getCountry() { return country; }
    void setCountry(string newCountry) { country = newCountry; }

    string getCity() { return city; }
    void setCity(string newCity) { city = newCity; }

    void printAddress() {
        cout << "Country: " << country << ", " << "City: " << city << endl;
    }
};