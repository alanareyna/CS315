//
// Created by Alana Reyna on 12/3/19.
//

#include "Tokenizer.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>

Tokenizer::Tokenizer(std::string name): inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);
}

//bool Tokenizer::charOfInterest(char c) {
//    return c == '=' || c == '+' || c == '-' || c == '*' || c == '%' || c == '/' ||
//    c == '(' || c == ')' || c == isupper(c) || c == islower(c);
//}

Token *Tokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && c == ' ') {}

//    if (! inputStream.good()) {
//        std::cout << "Tokenizer: Input stream seems corrupt. Terminating...\n";
//        exit(1);
//    }

//    Token * token = new Token();
    if (inputStream.eof()) {
        Token * token = new Token();

        token->eof(true);
        return token;
    }


    if (isupper(c)) {
        inputStream.putback(c);
        std::string roman;
        inputStream >> roman;
        Token * token = new Token(roman);

//            token = new Token(roman);
        token->isRomanNumber();
        return token;
    }
    else if (islower(c)) {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isAVariable();
        return token;
    }
    else if (c == '(') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isOpenParen();
        return token;
    }
    else if (c == ')') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isCloseParen();
        return token;
    }
    else if (c == '=') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isEqualSign();
        return token;
    }
    else if (c == '*') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isMultiplicationOperator();
        return token;
    }
    else if (c == '+') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isAdditionOperator();
        return token;
    }
    else if (c == '-') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isSubtractionOperator();
        return token;
    }
    else if (c == '%') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isModuloOperator();
        return token;
    }
    else if(c == '\n') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->eol(true);
        return token;
    }
    else if (c == '/') {
        Token * token = new Token(c);

//            token = new Token(c);
        token->isDivisionOperator();
        return token;
    }
    else {
        std::cout << "Bad character in input. The character is ->" << c << "<-\n";
        exit(1);
    }
}

//std::vector<Token *> &Tokenizer::tokenize() {
//    for (int i = 0; i < values.length(); i++) {
//        char curr = values[i];
//        if (!(curr == ' ')) {
//            if (!(curr == '\t')) {
//                if (isOperator(curr)) {
//                    tokens.push_back(new Token(curr));
//                }
//                else if (romanLetter(curr)) {
//                    std::string romanLetters = "";
//                    int j = i;
//                    char temp = values[j];
//                    while (romanLetter(temp)) {
//
//                    }
//                }
//            }
//        }
//    }
//}

//bool Tokenizer::romanLetter(char L) {
//    if (L == 'I')
//        return true;
//    else if (L == 'V')
//        return true;
//    else if (L == 'X')
//        return true;
//    else if (L == 'L')
//        return true;
//    else if (L == 'C')
//        return true;
//    else if (L == 'D')
//        return true;
//    else if (L == 'M')
//        return true;
//    else
//        return false;
//}
//
//bool Tokenizer::isOperator(char L) {
//    if (L == '=')
//        return true;
//    else if (L == '+')
//        return true;
//    else if (L == '-')
//        return true;
//    else if (L == '*')
//        return true;
//    else if (L == '%')
//        return true;
//    else if (L == '/')
//        return true;
//    else if (L == '(')
//        return true;
//    else if (L == ')')
//        return true;
//    else
//        return false;
//}