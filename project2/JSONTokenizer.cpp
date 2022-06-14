//
// Created by Alana Reyna on 11/7/19.
//

#include <iostream>
#include "JSONTokenizer.hpp"


JSONTokenizer::JSONTokenizer(std::string name): lineNumber{1},
                                                charPosition{0},
                                                inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);
}

bool JSONTokenizer::charOfInterest(char c) {
    return c == '[' || c == ']' || c == '{' || c == '}'
    || c == ':' || c == ',';
}

JSONToken JSONTokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }
    JSONToken jsonToken(lineNumber, charPosition);

    if (inputStream.eof()) {
        jsonToken.endOfFile() = true;
        return jsonToken;
    }
    while( inputStream.get(c)) {
        if (c == '[') {
            jsonToken.isOpenBracket() = true;
            return jsonToken;
        }
        else if (c == '{') {
            jsonToken.isOpenCurlyBracket() = true;
            return jsonToken;
        }
        else if (c == ':') {
            jsonToken.isColon() = true;
            return jsonToken;
        }
        else if (c == ',') {
            jsonToken.isComma() = true;
            return jsonToken;
        }
        else if (c == '"') {
            std::string s;
            while (inputStream.get(c) && c != '"') {
                s += c;
            }
            jsonToken.makeAttribute(s);
            //jsonToken.isAttribute() = true;
            return jsonToken;
        }
        else if (c == '}') {
            jsonToken.isCloseCurlyBracket() = true;
            return jsonToken;
        }
        else if (c == ']') {
            jsonToken.isCloseBracket() = true;
            return jsonToken;
        }
        else if (isnumber(c)) {
            inputStream.putback(c);
            double num;
            inputStream >> num;
            jsonToken.makeNum(num);
            //jsonToken.isNum() = true;
            return jsonToken;
        }
//        else {
//            std::cout << "error: token not found" <<std::endl;
//        }
    }

    return jsonToken;
}