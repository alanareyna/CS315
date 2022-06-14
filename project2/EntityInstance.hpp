//
// Created by Alana Reyna on 11/12/19.
//

#ifndef PROJECT2_ENTITYINSTANCE_HPP
#define PROJECT2_ENTITYINSTANCE_HPP

#include <iostream>
#include <vector>
#include "Pair.hpp"

class EntityInstance {
public:
    void addAttribute(Pair & pair);
    int numAttributes();
    std::vector<std::string> &attributeNames();
    void print();   // prints this object
    std::string getAttribute(std::string name);
    double getNumAttribute(std::string name);
    bool getString(std::string str);
    // more member functions here.

private:
    std::vector<Pair> entityAttributes;
    // more variables here.
};


#endif //PROJECT2_ENTITYINSTANCE_HPP
