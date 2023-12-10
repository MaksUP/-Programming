#pragma once
#include <iostream>

class Palindrome {
private:
    int number;

public:
    Palindrome(int number) {
        this->number = number;
    }

    ~Palindrome() {}

    bool isPalindrome() {
        int originalNumber = number;
        int reversedNumber = 0;

        while (number > 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }

        return originalNumber == reversedNumber;
    }
};