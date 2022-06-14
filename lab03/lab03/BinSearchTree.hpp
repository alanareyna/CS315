#include<stdlib.h>
#include "TreeNode.hpp"

class BinSearchTree {
public:
    void insert( int v );
    bool find( int v );
    bool iterFind( int v );
    int  size();
    void inorderDump();
    int  maxDepth();
    void levelOrderDump();
    bool remove( int v );
    int kthSmallest( int k );
    void valuesAtLevel( int k );
    void iterValuesAtLevel( int k );
    int iterMaxDepth();
    bool hasRootToLeafSum( int sum );
    bool areIdentical( BinSearchTree *bst );
    BinSearchTree *intersectWith( BinSearchTree *bst );
    BinSearchTree *unionWith( BinSearchTree *bst );
    BinSearchTree *differenceOf( BinSearchTree *bst );

    ~BinSearchTree();
private:
    TreeNode *local_insert( TreeNode *root, int v);
    int  size( TreeNode *root);
    bool find( TreeNode *root, int v);
    void inorderDump( TreeNode *root);
    int maxDepth( TreeNode *root);
    TreeNode * remove(TreeNode *root, int v);
    int kthSmallest(TreeNode *root, int k, int *counter);
    void valuesAtLevel(TreeNode *root, int k);
    void iterValuesAtLevel(TreeNode *root, int k);
    int iterMaxDepth(TreeNode *root);
    bool local_hasRootToLeaf(TreeNode *root, int sum, int totalSum);
    bool areIdentical(TreeNode *root, TreeNode *root2);
    void intersectWith(TreeNode *root, BinSearchTree *bst, BinSearchTree *newTree);
    void unionWith(TreeNode *root, BinSearchTree *bst);
    int lowerNum(TreeNode *root);
    void differenceOf(TreeNode *root, BinSearchTree *bst, BinSearchTree *newTree);
    TreeNode *root = nullptr;
    //int _size;
};
