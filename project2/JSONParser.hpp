//
// Created by Alana Reyna on 11/7/19.
//

#ifndef PROJECT2_JSONPARSER_HPP
#define PROJECT2_JSONPARSER_HPP

#include <iostream>
#include <string>
#include "JSONTokenizer.hpp"
#include "Entity.hpp"
#include "Pair.hpp"
#include "EntityInstance.hpp"

class JSONParser {
public:
    JSONParser(JSONTokenizer & tokenizer);

    Pair parseAPair();
    EntityInstance parseJSONObject();
    Entity parseJSONEntity();


private:
    JSONTokenizer &tokenizer;
};




#endif //PROJECT2_JSONPARSER_HPP
