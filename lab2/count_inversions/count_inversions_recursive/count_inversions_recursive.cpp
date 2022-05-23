//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/17/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#include "count_inversions_recursive.hpp"
#include <iostream>
#include <vector>
#include "read_input.hpp"

int count_inversions_recursive(const std::vector<int> &numbers) {
    int num_of_inversions = 0;
    int n = count(numbers);
    if (n == 1) {
        return 0;
    }
    else {

    }
}

int count(const std::vector<int> &numbers) {
    int n = 0;
    while (!numbers.end()) {
        n++;
    }
    std::cout << n << std::endl;
}
