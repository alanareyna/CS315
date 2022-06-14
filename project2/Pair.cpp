//
// Created by Alana Reyna on 11/12/19.
//
#include <iostream>
#include "Pair.hpp"


Pair::Pair(std::string attributeName, std::string attributeValue):  _attributeName{attributeName},
                                                                    _attributeStringValue{attributeValue},
                                                                    _isNumber{false} {}

Pair::Pair(std::string attributeName, double num):  _attributeName{attributeName},
                                                    _attributeNumberValue{num},
                                                    _isNumber{true} {}
bool Pair::isDouble() { return _isNumber;}

double Pair::numberValue() { return _attributeNumberValue; }

std::string Pair::stringValue() { return _attributeStringValue; }

std::string Pair::attributeName() { return _attributeName; }

void Pair::print() {
    std::cout << attributeName() << ":";
    if (isDouble())
        std::cout << numberValue() << std::endl;
    else
        std::cout << stringValue() << std::endl;
}

