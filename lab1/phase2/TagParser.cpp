//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/10/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "TagParser.hpp"
#include "Tokenizer.hpp"
#include "Token.hpp"

using namespace std;

TagParser::TagParser() {}

void TagParser::parser(string name) {
    Tokenizer tokenizer(name);

    Token token = tokenizer.getToken();
    while (!token.endOfFile()) {
        if (token.isOpenTag())
            handleOpenTag(tokenizer, token);
        else if (token.isCloseTag())
            handleCloseTag(tokenizer, token);
        else if(token.isCloseStandAloneTag())
            handleStandAloneCloseTag(tokenizer, token);
        else if(token.isCloseAngleBracket() || token.isOpenTag()) {
            token.print();
            std::cout << (token.isCloseAngleBracket() ? " ignoring random close angle-bracket."
                                                    : " ignoring random open angle-bracket.") << std::endl;
        } else {
            token.print();
            std::cout << " unknown token."  << std::endl;
        }
        token = tokenizer.getToken();
    }
    // to do                                                                                                                                                                                                

}

void TagParser::handleOpenTag(Tokenizer &tokenizer, Token &token) {
     token = tokenizer.getToken();

    if(token.isCloseAngleBracket()) {
        tag_stack.push_back(token);
    }
    else if(token.isCloseStandAloneTag()) {
        handleStandAloneCloseTag(tokenizer, token);
    }
    else {
        // call to print function?                                                                                                                                                                          
        // cout << "error: ignoring random open angle bracket." << endl;                                                                                                                                    
    }
}
void TagParser::handleCloseTag(Tokenizer &tokenizer, Token &token) {
    token = tokenizer.getToken();

    if (token.isCloseAngleBracket()) {
        if (tag_stack.back().tagName() == token.tagName()) {
            if (tags.find(token.tagName()) == tags.end()) {
                tags[token.tagName()] = std::vector<Token>();
            }
            tags[token.tagName()].push_back(tag_stack[tag_stack.size() - 1]);
            tags[token.tagName()].push_back(token);
            tag_stack.pop_back();
        }
    }
}
//change tokenizer to Token token, and change Token & token to Token & nextToken.                                                                                                                           
void TagParser::handleStandAloneCloseTag(Tokenizer &tokenizer, Token &token) {
    tags[token.tagName()] = std::vector<Token>();
    tags[token.tagName()].push_back(token);
    tag_stack.pop_back();
}
void TagParser::printReport() {

    cout << "The following is a list of well-formed HTML tags." << endl;

    // std::string location = "location.";                                                                                                                                                                  
    for(auto it = tags.begin(); it != tags.end(); ++it) {
        // our map, pairs an array of Tokens with tag-name strings.                                                                                                                                         
        std::vector<Token> locations = it->second;

        std::string location = "locations.";
        if (locations.size() == 1) {
            location = "location.";
        }
        cout << it->first << " appeared in the following " << locations.size() / 2 << location << endl;
        for(auto vIter = locations.begin();
            vIter != locations.end(); ++vIter) {
            vIter->print();
            std::cout << std::endl;
        }
    }

}
