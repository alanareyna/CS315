//
// Created by Alana Reyna on 12/5/19.
//

#include "Number.hpp"
#include <iostream>
#include <string>
#include <vector>

bool Number::isALegalRomanNumber() {
    Number n(stringNum);
    int val = n.intValue();
    int num = val;
    std::string d = romanValue();
    if (d == stringNum) {
        return true;
    }
    return false;

}

int Number::intValue() {
    return helperIntValue(stringNum);
}

int Number::helperIntValue(std::string stringNum){
    int total = 0;
    int i = 0;
    while (i < stringNum.size()) {
        if (stringNum[i] == 'C' && i + 1 < stringNum.size() && stringNum[i+1] == 'M') {
            total += 900;
            i += 2;
        }
        else if (stringNum[i] == 'M') {
            total += 1000;
            i++;
        }
        else if (stringNum[i] == 'C' && i + 1 < stringNum.size() && stringNum[i+1] == 'D') {
            total += 400;
            i += 2;
        }
        else if (stringNum[i] == 'D') {
            total += 500;
            i++;
        }
        else if (stringNum[i] == 'X' && i + 1 < stringNum.size() && stringNum[i+1] == 'C') {
            total += 90;
            i += 2;
        }
        else if (stringNum[i] == 'C') {
            total += 100;
            i++;
        }
        else if (stringNum[i] == 'X' && i + 1 < stringNum.size() && stringNum[i+1] == 'L') {
            total += 40;
            i += 2;
        }
        else if (stringNum[i] == 'L') {
            total += 50;
            i++;
        }
        else if (stringNum[i] == 'I' && i + 1 < stringNum.size() && stringNum[i+1] == 'X') {
            total += 9;
            i += 2;
        }
        else if (stringNum[i] == 'X') {
            total += 10;
            i++;
        }
        else if (stringNum[i] == 'I' && i + 1 < stringNum.size() && stringNum[i+1] == 'V') {
            total += 4;
            i += 2;
        }
        else if (stringNum[i] == 'V') {
            total += 5;
            i++;
        }
        else if (stringNum[i] == 'I') {
            total += 1;
            i++;
        }
        else {
            std::cout << "Error: invalid not a roman number" << std::endl;
        }
    }
    return total;
}


std::string Number::romanValue() {
//    return helperRomanValue(intNum);
    return stringNum;
}

std::string Number::helperRomanValue(int intNum) {
    std::vector<int> n = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    std::vector<std::string> romanLetters = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    if (intNum == 0) {
        return 0;
    }
    int i = 12;
    int tempNum = intNum;
    std::string romanNum;
    while (i >= 0) {
        while (tempNum / n[i] >= 1) {
            tempNum -= n[i];
            romanNum += romanLetters[i];
        }
        i--;
    }
    return romanNum;
}