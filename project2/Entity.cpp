//
// Created by Alana Reyna on 11/12/19.
//
#include "EntityInstance.hpp"
#include "Entity.hpp"
#include <iostream>
#include <vector>

Entity::Entity()  {}

void Entity::addObject(EntityInstance & insta) {
    instances.push_back(insta);
}


void Entity::print() {
    std::cout << "[" << std::endl;
    for (int i = 0; i < instances.size()-1; i++) {
        instances[i].print();
    }
    std::cout << "]" << std::endl;
}

Entity Entity::intersection(Entity & other) {
    // create new entity where we will store our new entity instance
    Entity newentity;

    // loop through first instances and save attribute for id as long as it is an id
    for (auto iter1:instances) {
        if (!iter1.getString("id"))
            continue;
        std::string id1 = iter1.getAttribute("id");

        // loop through second instances (other) and do the same as above
        for (auto iter2:other.instances) {
            if (!iter2.getString("id"))
                continue;
            std::string id2 = iter2.getAttribute("id");

            // if the ids are not the same skip over and break
            if (id1 != id2)
                continue;

            // make new entity instance, store id, previous gpa, and current gpa in three Pairs
            EntityInstance newentityinstance;
            Pair id("id",id2);
            Pair prevgpa("PrevGpa", iter2.getNumAttribute("gpa"));
            Pair currgpa("CurrGpa", iter1.getNumAttribute("gpa"));

            // add the three pairs we made into our new entity instance, then add that entity instance into our new entity
            newentityinstance.addAttribute(id);
            newentityinstance.addAttribute(prevgpa);
            newentityinstance.addAttribute(currgpa);
            newentity.addObject(newentityinstance);

            break;
        }
    }

    std::cout << "size of instance is: " << instances.size() << std::endl;
    return newentity;
}

int Entity::matrixBands(double gpa) {
    if (gpa <= 1.67)
        return 7;
    else if (gpa <= 2.0)
        return 6;
    else if (gpa <= 2.3)
        return 5;
    else if (gpa <= 2.67)
        return 4;
    else if (gpa <= 3.0)
        return 3;
    else if (gpa <= 3.3)
        return 2;
    else if (gpa <= 3.67)
        return 1;
    else
        return 0;
}

std::vector<std::vector <int>> Entity::makeMatrix() {
    // make a vector of vectors to make the matrix
    std::vector<std::vector <int>> matrix(8, std::vector<int> (8,0));

    // loop through instances and call the matrixBands of the current instance number attribute
    // use ++ with matrix so that it adds the number of students in that band
    for (int i = 0; i < instances.size(); i++) {
        int idx2 = matrixBands(instances[i].getNumAttribute("PrevGpa"));
        int idx1 = matrixBands(instances[i].getNumAttribute("CurrGpa"));
        matrix[idx1][idx2]++;
    }
    return matrix;
}


