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

    inputStream >> c;

    while ((c == ' ') || (c == '\t')) {
        inputStream >> c;
    }
    //inputStream.get(c);
//    if (! inputStream.good()) {
//        std::cout << "Tokenizer: Input stream seems corrupt. Terminating...\n";
//        exit(1);
//    }

//    Token * token = new Token();

    //Token * token = new Token(c);


    std::cout << " " << c << std::endl;
    if (inputStream.eof()) {
        Token * token = new Token();

        token->eof(true);
        return token;
    }

//    if ((c == ' ') || (c == '\t')) {
//        inputStream.get(c);
//    }



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
        Token *token = new Token(c);
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
        //std::cout << "EOL" << std::endl;
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

