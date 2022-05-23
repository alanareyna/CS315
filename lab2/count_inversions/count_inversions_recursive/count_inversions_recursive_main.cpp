//                                                                                                                                                                                                          
// Created by Alana Reyna on 9/17/19.                                                                                                                                                                       
//                                                                                                                                                                                                          

#include<iostream>
#include<string>
#include<vector>
#include "read_input.hpp"
#include "count_inversions_recursive.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }
    std::vector<int> numbers, result;
    read_numbers(std::string(argv[1]), numbers);

    std::cout << count_inversions_recursive(numbers) << std::endl;
    return 0;
}
