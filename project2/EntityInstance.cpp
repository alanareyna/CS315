//
// Created by Alana Reyna on 11/12/19.
//

#include "EntityInstance.hpp"
#include <iostream>

void EntityInstance::addAttribute(Pair & pair) {
    entityAttributes.push_back(pair);
}

int EntityInstance::numAttributes() {return entityAttributes.size(); }

void EntityInstance::print() {
    std::cout << "{" << std::endl;
    for(int i = 0; i < entityAttributes.size(); i++){
        //std::cout << "entityInstance print" << std::endl;
        entityAttributes[i].print();
    }
    std::cout << "}" << std::endl;
}

std::string EntityInstance::getAttribute(std::string name) {
    for(int i = 0; i < entityAttributes.size(); i++ ) {
        if (entityAttributes[i].attributeName() == name) {
            return entityAttributes[i].stringValue();
        }
    }
}

double EntityInstance::getNumAttribute(std::string name) {
    for(int i = 0; i < entityAttributes.size(); i++) {
        if (entityAttributes[i].attributeName() == name) {
            return entityAttributes[i].numberValue();
        }
    }
}

bool EntityInstance::getString(std::string name) {
    for (int i = 0; i < entityAttributes.size(); i++) {
        if (entityAttributes[i].attributeName() == name) {
            return true;
        }
    }
    return false;
}