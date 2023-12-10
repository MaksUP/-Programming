#pragma once
#include <string>
using namespace std;

class Coursework {
private:
	string title;
	string description;
	string deliveryDate;

public:
	Coursework(string title = "", string description = "", string deliveryDate = "") {
		this->title = title;
		this->description = description;
		this->deliveryDate = deliveryDate;
	}

	~ Coursework() {}

	string getTitle() { return title; }
	void setTitle(string newTitle) { title = newTitle; }

	string getDescription() { return description; }
	void setDescription(string newDescription) { description = newDescription; }

	string getDeliveryDate() { return deliveryDate; }
	void setDeliveryDate(string newDeliveryDate) { deliveryDate = newDeliveryDate; }

	void printCoursework() {
		cout << "Title: " << title << ", " << "Description: " << description << ", " << "Delivery date: " << deliveryDate << endl;
	}
};