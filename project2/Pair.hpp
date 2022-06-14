//
// Created by Alana Reyna on 11/12/19.
//

#ifndef PROJECT2_PAIR_HPP
#define PROJECT2_PAIR_HPP

#include <iostream>
#include <string>

class Pair {
public:
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double num);
    bool isDouble();  // is the datatype of the value of this attribute a double?
    double numberValue();
    std::string stringValue();
    std::string attributeName();
    void print();

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};


#endif //PROJECT2_PAIR_HPP
