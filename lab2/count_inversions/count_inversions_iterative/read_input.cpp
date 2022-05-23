//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/17/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "read_input.hpp"

void read_numbers(std::string filename, std::vector<int> &v) {

    std::ifstream file (filename);
    int count = 0;
    if (file) {
        while (file >> count) {
            v.push_back(count);
        }
    }
    else {
        std::cout << "error: cannot open file" << std::endl;
    }
}
