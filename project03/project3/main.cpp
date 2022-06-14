#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Number.hpp"
#include "TokenIterator.hpp"
#include "InfixToPostfix.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <ostream>
#include <map>
#include <stack>
#include <vector>


//void putInVect(std::vector<Token *> toks, Token *nextToken) {
//    while(!nextToken->eof()) {
//        toks.push_back(nextToken);
//    }
//    toks.push_back(nextToken);
//}

void solveExpression(std::vector<Token *> postFixTokens, std::vector<int> romanPostFixTokens) {
    SymbolTable symboltable;
    for (auto token: postFixTokens) {
        if (token->isRomanNumber()) {
            Number romanNum(token->romanNumber());
            if (romanNum.isALegalRomanNumber()) {
                romanPostFixTokens.push_back(romanNum.intValue());
            }
            else {
                std::cout << "Error: not a legal Roman Number" << std::endl;
                exit(2);
            }
        }
        else if (token->isAVariable()){
            if (!symboltable.exits(token->getVariable())) {
                std::cout << "Error: not on the map" << std::endl;
                exit(2);
            }
            else {
                int val = symboltable.value(token->getVariable());
                romanPostFixTokens.push_back(val);
            }
        }
        else if (token->isAdditionOperator()) {
            int right = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int left = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int sum = left + right;
            romanPostFixTokens.push_back(sum);
        }
        else if (token->isSubtractionOperator()) {
            int right = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int left = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int sum = left - right;
            romanPostFixTokens.push_back(sum);
        }
        else if (token->isMultiplicationOperator()) {
            int right = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int left = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int sum = left * right;
            romanPostFixTokens.push_back(sum);
        }
        else if (token->isDivisionOperator()) {
            int right = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int left = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int sum = left / right;
            romanPostFixTokens.push_back(sum);
        }
        else if (token->isModuloOperator()) {
            int right = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int left = romanPostFixTokens.back();
            romanPostFixTokens.pop_back();
            int sum = left % right;
            romanPostFixTokens.push_back(sum);
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }
}


int main(int argc, char *argv[]) {

    std::cout << " here";
    // This function demonstrates the use of the InfixToPostfix class 
    // and its member-functionm, convert. To that end, the tokens 
    // have been hard coded instead of using a tokenizer to 
    // identify them.
    Tokenizer tokenizer(argv[1]);

    Token *token = tokenizer.getToken();

    SymbolTable symbolTable;



    while (!token->eof()) {


        if (!token->isAVariable()) {
            std::cout << "Error: not a variable" << std::endl;
            exit(2);
        }

        char name = token->getVariable();
        token = tokenizer.getToken();

        if (!token->isEqualSign()) {
            std::cout << "Error: not an equal sign" << std::endl;
            exit(2);
        }

        token = tokenizer.getToken();

        std::vector<Token *> infixTokens;


        while (!token->eol()) {
            infixTokens.push_back(token);
            token = tokenizer.getToken();
        }
        infixTokens.push_back(token);



        std::vector<Token *> postFixTokens;

        InfixToPostfix inToPost;

        inToPost.convert(infixTokens, postFixTokens);

        std::vector<int> romanPostFixTokens;

        solveExpression(postFixTokens, romanPostFixTokens);

        symbolTable.setVal(name, romanPostFixTokens[0]);

        Number n(romanPostFixTokens[0]);

        std::cout << name << " equals " << " " << n.romanValue() << std::endl;

        token = tokenizer.getToken();
    }


    return 0;
}


//std::vector<Token *> line(std::vector<Token *> vectOfTokens, std::map<char, int> romanMap, char & c) {
//    std::vector<Token *> finTokens;
//    if (!vectOfTokens[0]->isAVariable()) {
//        std::cout << "Error: not a variable" << std::endl;
//        exit(2);
//    }
//
//    c = vectOfTokens[0]->isAVariable();
//
//    if (!vectOfTokens[1]->isEqualSign()) {
//        std::cout << "Error: not an equal sign" << std::endl;
//        exit(2);
//    }
//
//}
//
//int topValue(std::stack<int> &stack) {
//    if (stack.empty()) {
//        std::cout << "main: Pop operation on an empty stack is not a good idea. Terminating...";
//        exit(1);
//    }
//    int top = stack.top();
//    stack.pop();
//    return top;
//}
//
//int evaluateExpression(const std::vector<Token> &exprTokens) {
//    std::stack<int> evalStack;
//    int top = 0;
//    for (Token token : exprTokens) {}
//
//}



//    std::vector<Token *> tokens = std::vector<Token *>();
//
//
//
//    // Suppose that the input contained the following expression.
//    // a = XX + XXX  * XXXV + (XXX - XXXII) + II
//    // a = 20 + 30 * 35 + (30 + 32) + 2
//
//    tokens.push_back(new Token('a'));     // variable a
//    tokens.push_back(new Token('='));     //
//    tokens.push_back(new Token("XX"));     // 20
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token( "XXX"));  // 30
//    tokens.push_back(new Token('*'));
//    tokens.push_back(new Token( "XXXV"));  // 35
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token('('));
//    tokens.push_back(new Token("XXXII"));  // 32
//    tokens.push_back(new Token('-'));
//    tokens.push_back(new Token( 'c'));   // 30
//    tokens.push_back(new Token(')'));
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token("II"));    // 2
//    Token *token = new Token();
//    token->eol(true);
//    tokens.push_back(token);
//
//    int numTokens = tokens.size();
//    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
//    for( auto token : tokens )
//        token->print();
//    std::cout << std::endl;
//
//    InfixToPostfix *itop = new InfixToPostfix();
//    std::vector<Token *> postfixTokens;
//    itop->convert( tokens, postfixTokens );
//    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
//    for( auto postfixToken : postfixTokens)
//        postfixToken->print();
//    std::cout << std::endl;