//
// Created by Alana Reyna on 11/7/19.
//

#include "JSONParser.hpp"
#include "JSONTokenizer.hpp"

JSONParser::JSONParser(JSONTokenizer & tokenizer):  tokenizer{tokenizer} {}

Pair JSONParser::parseAPair() {
    JSONToken jsonToken1 = tokenizer.getToken();
    JSONToken jsonToken2 = tokenizer.getToken();
    JSONToken jsonToken3 = tokenizer.getToken();
    if(jsonToken1.isAttribute()) {

        if (jsonToken2.isColon()) {

            if (jsonToken3.isNum())
                return Pair(jsonToken1.tagName(), jsonToken3.returnDouble());
            else if (jsonToken3.isAttribute())
                return Pair(jsonToken1.tagName(), jsonToken3.tagName());

        }
    }
}

EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenCurlyBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseCurlyBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

Entity JSONParser::parseJSONEntity() {
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    Entity instances;
    do {
        EntityInstance entityInstance = parseJSONObject();
        instances.addObject(entityInstance);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instances;
}

