//
// Created by Alana Reyna on 12/5/19.
//

#ifndef PROJECT1_SYMBOLTABLE_HPP
#define PROJECT1_SYMBOLTABLE_HPP

#include <iostream>
#include <map>

class SymbolTable {
public:
    int value(char v) {
        return romanMap[v];
    }

    void setVal(char v, int val) {
        romanMap[v] = val;
    }
    bool exits (char c) {
        if (romanMap.count(c) == 0) {
            return false;
        }
        return true;
    }

private:
    std::map<char, int> romanMap;
};


#endif //PROJECT1_SYMBOLTABLE_HPP
