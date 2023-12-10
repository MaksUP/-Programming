#include <iostream>							
#include <Windows.h>
#include <string>
using namespace std;

class Human {
private:

	int Weight;
	int Height;
	int Age;
	string Name;

public:

	Human() {
		Weight = Height = Age = 0;
		Name = "0";
	}

	Human(int Weight, int Height, int Age, string Name) {
		this->Weight = Weight;
		this->Height = Height;
		this->Age = Age;
		this->Name = Name;
	}

	string GetInfo() {
		return "Âàãà: " + to_string(Weight) + "\n"
			   "Çð³ñò: " + to_string(Height) + "\n"
			   "Â³ê: " + to_string(Age) + "\n"
			   "²ì'ÿ: " + Name + "\n";
	}

	int GetWeight() { return Weight; }
	int GetHeight() { return Height; }
	int GetAge() { return Age; }
	string GetName() { return Name; }

	void SetWeight(int Weight) { this->Weight = Weight; }
	void SetHeight(int Height) { this->Height = Height; }
	void SetAge(int Age) { this->Age = Age; }
	void SetName(string Name) { this->Name = Name; }
};

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Human properties;
	properties.SetWeight(65);
	cout << properties.GetWeight() << endl;

	cout << properties.GetInfo() << endl;

	system("pause");
	return 0;
}