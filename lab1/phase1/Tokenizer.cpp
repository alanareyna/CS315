//                                                                                                                                                                                                          
// Created by Alana Reyna on 8/21/18.                                                                                                                                                                   
//                                                                                                                                                                                                          

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name): lineNumber{1},
                                        charPosition{1},
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.                                                                                  
}

bool Tokenizer::charOfInterest(char c) {
    if(c == '<' || c == '>' || c == '/'){
        return true;
    }
    else {
        return false;
    }
    // is c the initial (or the sole) character of a token?                                                                                                                                                 
    // you need to replace this with code that compares c with characters like '<', '>', etc.                                                                                                               
}

Token Tokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && ! charOfInterest(c) ) {
        // keep track of the line number and the character position                                                                                                                                         
        charPosition++;
        if(c == '\n') {
            lineNumber++;
        }
    }

    Token token(lineNumber, charPosition);
    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }


    if( c == '<' ) { // A possible open tag.                                                                                                                                                                
        if(inputStream.peek() == '/') {
            inputStream.get(c);
            charPosition++;
            std::string s = "";
            while (inputStream.get(c) && isalnum(c)) {
                s += c;
                charPosition++;
            }
            inputStream.putback(c);
            //charPosition--;                                                                                                                                                                               
            token.makeCloseTag(s);
            return token;
            }
        else if(isalnum(inputStream.peek()) == true) {
            std::string a = "";
            while (inputStream.get(c) && isalnum(c)) {
                a += c;
                charPosition++;
            }
            inputStream.putback(c);
            //charPosition--;                                                                                                                                                                               
            token.makeOpenTag(a);
            return token;
        }
    }
    if(c == '/') {
        inputStream.get(c);
        charPosition++;

        if (inputStream.peek() == '>') {
            token.isCloseStandAloneTag() = true;
            return token;
        }
    }
    if( c == '>' ) {
        token.isCloseAngleBracket() = true;
        return token;
    } else {
        std::cout << "Tokenizer::getToken: error: not a proper tag" << std::endl;
    }

    return token;
    // ... more if-else statements here.                                                                                                                                                                    
    // return token;                                                                                                                                                                                        
}
