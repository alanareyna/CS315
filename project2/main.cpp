#include <iostream>
#include <ostream>
#include "JSONParser.hpp"

#include "Entity.hpp"

#include "JSONTokenizer.hpp"


int main(int argc, char *argv[]) {
    std::ifstream inputStream1;
    std::ifstream inputStream2;
    inputStream1.open(argv[1], std::ios::in);
    inputStream2.open(argv[2], std::ios::in);
    if (!inputStream1.is_open()) {
        std::cout << "Unable to open" << argv[1] << ". Terminating...";
        exit(2);
    }
    else if (!inputStream2.is_open()) {
        std::cout << "Unable to open" << argv[1] << ". Terminating...";
        exit(2);
    }

    inputStream1.close();
    inputStream2.close();

    JSONTokenizer jsonTokenizer1(argv[1]);
    JSONTokenizer jsonTokenizer2(argv[2]);

    JSONParser * parser1 = new JSONParser(jsonTokenizer1);
    Entity entity1 = parser1->parseJSONEntity();

    //entity1.print();
    JSONParser * parser2 = new JSONParser(jsonTokenizer2);
    Entity entity2 = parser2->parseJSONEntity();

    Entity entity3 = entity1.intersection(entity2);

    std::vector<std::vector<int>> myMatrix = entity3.makeMatrix();
    std::ofstream file;
    file.open("cs315project2.json");
    file << "[" << std::endl;

    for (int i = 0; i <= 7; i++) {
        file << "[";
        for (int j = 0; j <= 7; j++) {
            if (j < 7)
                file << myMatrix[i][j] << ", ";
            else
                file << myMatrix[i][j];
        }
        if (i < 7)
            file << "]," << std::endl;
        else
            file << "]" << std::endl;
    }
    file << "]" << std::endl;

    return 0;
}