//
// Created by Alana Reyna on 11/7/19.
//

#ifndef PROJECT2_JSONTOKEN_HPP
#define PROJECT2_JSONTOKEN_HPP

#include <string>
#include <iomanip>

class JSONToken {
public:
    JSONToken(int, int);
    bool &isOpenBracket();
    bool &isCloseBracket();
    bool &isOpenCurlyBracket();
    bool &isCloseCurlyBracket();
    bool &isColon();
    bool &isComma();
    bool &isDoublyQuotedString();
    bool &endOfFile();

    double returnDouble();
    bool &isAttribute();
    bool &isNum();

    std::string tagName();

    void makeAttribute(std::string);
    void makeNum(double);

    void print();

private:
    bool _isOpenBracket, _isCloseBracket, _isOpenCurlyBracket,
            _isCloseCurlyBracket, _eof, _isColon, _isComma, _isDoublyQuotedString, _isAttribute, _isNum;
    std::string _tagName;
    double _number;
    int  _lineNumber, _charPos;
};


#endif //PROJECT2_JSONTOKEN_HPP
