//
// Created by Alana Reyna on 12/3/19.
//

#ifndef PROJECT1_TOKENIZER_HPP
#define PROJECT1_TOKENIZER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Token.hpp"

class Tokenizer {
public:
    Tokenizer(std::string);
    Token *getToken();

private:
    std::string values;
    std::vector<Token *> tokens;
    std::string inputFileName;
    std::ifstream inputStream;
    bool charOfInterest(char c);
//    bool romanLetter(char L);
//    bool isOperator(char L);
};


#endif //PROJECT1_TOKENIZER_HPP
