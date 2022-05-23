//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/17/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#include "count_inversions_iterative.hpp"
#include <iostream>
#include <vector>
#include "read_input.hpp"

int count_inversions_iterative(const std::vector<int> &numbers) {
    int num_of_inversions = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] > numbers[i+1]) {
            num_of_inversions++;
        }
    }
    return num_of_inversions;
}
