//
// Created by Alana Reyna on 11/7/19.
//

#include <iostream>
#include <iomanip>
#include "JSONToken.hpp"

JSONToken::JSONToken(int line, int pos): _isOpenBracket{false},
                                         _isCloseBracket{false},
                                         _isOpenCurlyBracket{false},
                                         _isCloseCurlyBracket{false},
                                         _isColon{false},
                                         _isComma{false},
                                         _isDoublyQuotedString{false},
                                         _eof{false},
                                         _isAttribute{false},
                                         _isNum{false},
                                         _number{0.00},
                                         _tagName{""},
                                         _lineNumber{line},
                                         _charPos{pos} {}

bool &JSONToken::isOpenBracket() { return _isOpenBracket; }

bool &JSONToken::isCloseBracket() { return _isCloseBracket; }

bool &JSONToken::isOpenCurlyBracket() { return _isOpenCurlyBracket; }

bool &JSONToken::isCloseCurlyBracket() { return _isCloseCurlyBracket; }

bool &JSONToken::endOfFile() { return _eof; }

bool &JSONToken::isColon() { return _isColon; }

bool &JSONToken::isComma() { return _isComma; }

bool &JSONToken::isDoublyQuotedString() { return _isDoublyQuotedString; }

bool &JSONToken::isAttribute() { return _isAttribute; }

bool &JSONToken::isNum() { return _isNum; }

double JSONToken::returnDouble() { return _number; }

void JSONToken::makeAttribute(std::string name) {
    _tagName = name;
    this -> isAttribute() = true;
}

void JSONToken::makeNum(double n) {
    _number = n;
    this -> isNum() = true;
}

std::string JSONToken::tagName() { return _tagName; }

void JSONToken::print() {
    if (isOpenBracket())
        std::cout << "[" << std::endl;
    else if (isCloseBracket())
        std::cout << "]" << std::endl;
    else if (isOpenCurlyBracket())
        std::cout << "{" << std::endl;
    else if (isCloseCurlyBracket())
        std::cout << "}" << std::endl;
    else if (isColon())
        std::cout << ":" << std::endl;
    else if (isComma())
        std::cout << "," << std::endl;
    else if (isDoublyQuotedString())
        std::cout << '"' << std::endl;
    else if (isAttribute())
        std::cout << tagName() << std::endl;
    else if (isNum())
        std::cout << returnDouble() << std::endl;
 }












