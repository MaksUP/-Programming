#include <iostream>
#include <Windows.h>

#include "Address.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

void task1() {
    int last;
    for (int x = 0; x < 100; x++) {
        last = x;
    }
    cout << "The value of x after the loop is finished: " << last << "\n";
}

void task2() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "0 ";
        }
        cout << "\n";
    }
}

void task3() {
    for (int i = 100; i <= 200; i += 2) {
        cout << i << " ";
    }
    cout << "\n" << "\n";


    int i = 100;
    while (i <= 200) {
        cout << i << " ";
        i += 2;
    }
    cout << "\n" << "\n";


    int j = 100;
    do {
        cout << j << " ";
        j += 2;
    } while (j <= 200);
    cout << "\n";
}

void task4() {
    int num;

    while (true) {
        cout << "Enter a number from the specified range (0, 10): ";
        cin >> num;

        if (num < 0 || num > 10) {
            cout << "You entered a number outside the specified range. Please try again" << "\n";
        }
        else {
            cout << "The number is valid" << "\n";
            break;
        }
    }
}

void task5() {
    int amount;
    cout << "Enter the number of numbers: ";
    cin >> amount;

    int sum = 0;
    int product = 1;

    for (int i = 0; i < amount; i++) {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        sum += num;
        product *= num;

        char сontinue;
        if (i != amount-1) {
            cout << "Continue entering? (y/n): ";
            cin >> сontinue;
            
            if (сontinue != 'y') {
                break;
            }
        }
    }
    cout << "\n";

    cout << "The sum of the entered numbers: " << sum << "\n";
    cout << "The product of the entered numbers: " << product << "\n";
}

void task6() {
    cout << "while (counter < 10)" << "\n";
    cout << "Помилки:" << "\n" << "1. Немає ініціалізації лічильника" << "\n" << 
                                  "2. Немає оновлення лічильника" << "\n";
}

void task7() {
    cout << "for (int counter = 0; counter < 10; conter++); cout << “counter: ” << counter;" << "\n";
    cout << "Помилки:" << "\n" << "1. Виведення counter знаходиться не в тілі циклу / змінну counter не можна вивести поза циклом через її локальність" << "\n"
                                  "2. Неправильно визначена змінна counter при її інкрементації в циклі" << "\n";
}

void task8() {
    cout << "while (counter < 10) { cout << “counter: ” << counter; counter--; }" << "\n";
    cout << "Помилки:" << "\n" << "1. Немає ініціалізації лічильника" << "\n" <<
                                  "2. Якщо декрементувати counter при counter < 10, такий цикл буде нескінченним" << "\n";
}

void task9() {
    string objectType;
    bool isAddress = false;
    bool isHuman = false;
    Address saveAddress;
    Human saveHuman;
    vector<Student *> listStudents;

    while (true) {
        cout << "Enter object type (Address, Human, Student or Teacher) or 'exit' to quit: ";
        cin >> objectType;

        // exit
        if (objectType == "exit") {
            break;
        }

        // Address
        if (objectType == "Address") {
            string country, city;

            cout << "Enter country: ";
            cin >> country;
            cout << "Enter city: ";
            cin >> city;
            cout << "Successfully" << "\n";

            Address address(country, city);
            saveAddress = address;
            isAddress = true;
            cout << "\n";
            address.printAddress();
            cout << "\n";
            continue;
        }

        // Human
        if (objectType == "Human") {
            if (isAddress) {
                string name, surname, gender;
                int age;

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter surname: ";
                cin >> surname;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter gender: ";
                cin >> gender;
                cout << "Successfully" << "\n";

                Human human(name, surname, age, gender, saveAddress);
                saveHuman = human;
                isHuman = true;
                cout << "\n";
                human.printInfo();
                cout << "\n";
                continue;
            }
            else {
                cout << "First, enter the address" << "\n";
                continue;
            }
        }

        // Student
        if (objectType == "Student") {
            if (isHuman) {
                float scholarship;
                string group;

                cout << "Enter scholarship: ";
                cin >> scholarship;
                cout << "Enter group: ";
                cin >> group;
                cout << "Successfully" << "\n";

                Student student(saveHuman, scholarship, group);
                listStudents.push_back(&student);
                cout << "\n";
                student.printInfo();
                cout << "\n";
                continue;
            }
            else {
                cout << "First, enter the human" << "\n";
                continue;
            }
        }

        // Teacher
        if (objectType == "Teacher") {
            if (isHuman) {
                float salary;

                cout << "Enter salary: ";
                cin >> salary;
                cout << "Successfully" << "\n";

                Teacher teacher(saveHuman, salary, listStudents);
                cout << "\n";
                teacher.printInfo();
                cout << "\n";
                continue;
            }
            else {
                cout << "First, enter the human" << "\n";
                continue;
            }
        }
    }
}

void task10() {

    // 1
    int num;
    cout << "Enter the serial number of the day of the week (1, 2, 3, 4, 5, 6, 7): ";
    cin >> num;

    switch (num) {
    case 1: cout << "Monday" << "\n";
        break;
    case 2: cout << "Tuesday" << "\n";
        break;
    case 3: cout << "Wednesday" << "\n";
        break;
    case 4: cout << "Thursday" << "\n";
        break;
    case 5: cout << "Friday" << "\n";
        break;
    case 6: cout << "Saturday" << "\n";
        break;
    case 7: cout << "Sunday" << "\n";
        break;
    default: cout << "There is no such day" << "\n";
        break;
    }

    // 2
    char letter;
    cout << "Enter the first letter of the day of the week (M, T, W, t, F, S, s): ";
    cin >> letter;

    switch (letter) {
    case 'M': cout << "Monday" << "\n";
        break;
    case 'T': cout << "Tuesday" << "\n";
        break;
    case 'W': cout << "Wednesday" << "\n";
        break;
    case 't': cout << "Thursday" << "\n";
        break;
    case 'F': cout << "Friday" << "\n";
        break;
    case 'S': cout << "Saturday" << "\n";
        break;
    case 's': cout << "Sunday" << "\n";
        break;
    default: cout << "There is no such day" << "\n";
        break;
    }

    // 3
    enum DaysOfWeek {
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    DaysOfWeek name = Friday;

    switch (name) {
    case Monday: cout << "Monday" << "\n";
        break;
    case Tuesday: cout << "Tuesday" << "\n";
        break;
    case Wednesday: cout << "Wednesday" << "\n";
        break;
    case Thursday: cout << "Thursday" << "\n";
        break;
    case Friday: cout << "Friday" << "\n";
        break;
    case Saturday: cout << "Saturday" << "\n";
        break;
    case Sunday: cout << "Sunday" << "\n";
        break;
    default: cout << "There is no such day" << "\n";
        break;
    }
}

void task11() {
    double point;
    cout << "Введіть бал інтенсивності землетрусу: ";
    cin >> point;

    if (point < 5) { cout << "Легке, немає руйнувань" << "\n"; }
    else if (point < 5.5) { cout << "Середнє, невеликі руйнування" << "\n"; }
    else if (point < 6.5) { cout << "Серйозне, руйнування та пошкодження стін" << "\n"; }
    else if (point < 7.5) { cout << "Лихо, багато будинків та будівель пошкоджено" << "\n"; }
    else { cout << "Катастрофа, більшість будинків та будівель зруйновано" << "\n"; }
}

int task12() {
    int power, serviceLife;
    cout << "Enter the power of the light bulb (W): ";
    cin >> power;

    if (power == 25) { serviceLife = 2500; }
    else if (power == 40 || power == 60) { serviceLife = 1000; }
    else if (power == 75 || power == 100) { serviceLife = 750; }
    else if (power == 150 || power == 200) { serviceLife = 500; }
    else {
        cout << "There is no such power" << "\n";
        return 0;
    }

    cout << "Service life of the light bulb: " << serviceLife << " hours" << "\n";
}

void task13() {
    cout << "case 2: cout << “White\\n”; default: cout << “Other\\n”" << "\n";
    cout << "Помилки:" << "\n" << "1. Немає оператора switch, без нього case існувати не може" << "\n" <<
                                  "2. Відсутній оператор break, без якого програма продовжить перевіряти всі останні case" << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //task1(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task2(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task3(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task4(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task5(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task6(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task7(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task8(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task9(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task10(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task11(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task12(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
    //task13(); cout << "\n" << "========================================================================================================================" << "\n" << "\n";
 
    return 0;
}