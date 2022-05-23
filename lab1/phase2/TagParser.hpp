//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/10/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#ifndef LAB01_2_TAGPARSER_HPP
#define LAB01_2_TAGPARSER_HPP
#include <fstream>
#include <vector>
#include <tic.h>
#include "Token.hpp"
#include "Tokenizer.hpp"

class TagParser {
public:
    TagParser();
    void parser(std::string);
    void handleOpenTag(Tokenizer &tokenizer, Token &token);
    void handleCloseTag(Tokenizer &tokenizer, Token &token);
    void handleStandAloneCloseTag(Tokenizer &tokenizer, Token &token);
    void printReport();


private:
    std::vector<Token> tag_stack;
    std::map<std::string, std::vector<Token> > tags;
    std::string inputFileName;
    std::ifstream inputStream;
};


#endif //LAB01_2_TAGPARSER_HPP  
