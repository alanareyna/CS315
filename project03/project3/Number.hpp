//
// Created by Alana Reyna on 12/5/19.
//

#ifndef PROJECT1_NUMBER_HPP
#define PROJECT1_NUMBER_HPP

#include <iostream>
#include <string>

class Number {
public:
    Number (int n) { intNum = n;}
    Number (std::string num) { stringNum = num; }
    bool isALegalRomanNumber();
    int intValue();
    int helperIntValue(std::string stringNum);
    std::string romanValue();
    std::string helperRomanValue(int intNum);
private:
    std::string stringNum;
    int intNum;
};


#endif //PROJECT1_NUMBER_HPP
