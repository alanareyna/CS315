//
// Created by Alana Reyna on 11/12/19.
//

#ifndef PROJECT2_ENTITY_HPP
#define PROJECT2_ENTITY_HPP


#include "EntityInstance.hpp"

class Entity {
public:
    Entity();

    void addObject(EntityInstance &);
    void print(); // prints all instances of this Entity.
    Entity intersection(Entity & other);
    int matrixBands(double);
    std::vector <std::vector <int>> makeMatrix();

    // more member functions here.

private:
    std::vector<EntityInstance> instances;
};


#endif //PROJECT2_ENTITY_HPP
