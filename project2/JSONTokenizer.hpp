//
// Created by Alana Reyna on 11/7/19.
//

#ifndef PROJECT2_JSONTOKENIZER_HPP
#define PROJECT2_JSONTOKENIZER_HPP
#include <string>
#include <fstream>
#include "JSONToken.hpp"

class JSONTokenizer {

public:
    JSONTokenizer(std::string);
    JSONToken getToken();

private:
    int lineNumber, charPosition;
    std::string inputFileName;
    std::ifstream inputStream;
    bool charOfInterest(char c);
};


#endif //PROJECT2_JSONTOKENIZER_HPP
