#pragma once
#include <vector>
#include "Human.h"

class ListHumans {
private:
	vector<Human*> listHumans;	// присвоєння об'єктів по вказівнику на базовий клас 

public:
	ListHumans(vector<Human*> listHumans = {}) {
		this->listHumans = listHumans;
	}

	~ ListHumans() {}

	vector<Human*> getListHumans() { return listHumans; }
	void setListHumans(vector<Human*> newListHumans) { listHumans = newListHumans; }

	void addHuman(Human *human) {
		listHumans.push_back(human);
	}

	void deleteHuman(Human *human) {
		listHumans.erase(remove(listHumans.begin(), listHumans.end(), human), listHumans.end());  // erase–remove idiom
	}

	void printHumans() {
		for (auto human:listHumans) {
			human->printInfo();
		};
	}
};