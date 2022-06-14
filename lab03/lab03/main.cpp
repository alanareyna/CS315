#include <iostream>
#include <fstream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main(int argc, char *argv[]) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.

    BinSearchTree *tree = new BinSearchTree();
    std::ifstream file;
    file.open(argv[1]);

    int v;
    while( file >> v ) {
        tree->insert( v );
    }
    tree->insert(v);

    std::cout<< "find: " << tree->find(8) << std::endl;
    std::cout << "Iter find: " << tree->iterFind(8) << std::endl;
    std::cout << "tree size: " << tree->size() << std::endl;
    std::cout << "dump: " << std::endl;
    tree->inorderDump();
    std:: cout << "depth: " << tree->maxDepth() << std::endl;
    std::cout << "iterLevelOrderDump: " << std::endl;
    std::cout << "level order dump:" << std::endl;
    tree->levelOrderDump();
    std::cout << "remove: " << tree->remove(5) << std::endl;
    std::cout << "kth smallest: " << tree->kthSmallest(1) << std::endl;
    std::cout << "intersect with: " << tree->intersectWith(bst) << std::endl;



    return 0;
}