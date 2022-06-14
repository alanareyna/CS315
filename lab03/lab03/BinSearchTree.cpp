//
// Created by Alana Reyna on 10/8/19.
//
#include <iostream>
#include <queue>
#include "BinSearchTree.hpp"


TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( local_insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( local_insert( root->leftSubtree(), v ) );
    return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
        root = local_insert( root, v );
}

bool BinSearchTree::find(int v) {
    return find(root, v);
}

bool BinSearchTree::find( TreeNode *root, int v) {
    if (root == nullptr)
        return false;
    if (root->value() == v)
        return true;
    if (root->value() > v)
        return find(root->leftSubtree(), v);
    return find(root->rightSubtree(), v);
}

bool BinSearchTree::iterFind(int v) {
    TreeNode * newRoot = root;
    while (newRoot != nullptr) {
        if( newRoot->value() == v )
            return true;
        if (newRoot->value() < v)
            newRoot = newRoot->rightSubtree();
        else
            newRoot = newRoot->leftSubtree();
    }
    return false;
}

int BinSearchTree::size() {
    return size(root);
}

int BinSearchTree::size( TreeNode *root) {
    if (root == nullptr)
        return 0;
    return 1 + size(root->leftSubtree()) + size(root->rightSubtree());
}

void BinSearchTree::inorderDump() {
    inorderDump(root);
}

void BinSearchTree::inorderDump( TreeNode *root) {
    if (root == nullptr)
        return;
    inorderDump(root->leftSubtree());
    std::cout << root->value() << std::endl;
    inorderDump(root->rightSubtree());
}

int BinSearchTree::maxDepth() {
    return maxDepth(root);
}

int BinSearchTree::maxDepth( TreeNode *root) {
    if (root == nullptr)
        return 0;
    if (root->leftSubtree() == nullptr && root->rightSubtree() == nullptr)
        return 1;
    else {
        int L = maxDepth(root->leftSubtree());
        int R = maxDepth(root->rightSubtree());
        if (L > R)
            return L+1;
        else
            return R+1;
    }
}

void BinSearchTree::levelOrderDump() {
    std::queue<TreeNode *> q;
    if (root == nullptr)
        return;
    q.push(root);
    q.push(NULL);
    TreeNode * n;
    while (q.size() > 1) {
        n = q.front();
        q.pop();
        if (n == NULL){
            q.push(NULL);
            //std::cout << "\n";
        }
        else {
            if (n->leftSubtree())
                q.push(n->leftSubtree());
            if (n->rightSubtree())
                q.push(n->rightSubtree());

            std::cout << n->value() << std::endl;
        }
    }
}

bool BinSearchTree::remove(int v) {
    if(!find(v))
        return false;
    return remove(root, v);
}

TreeNode * BinSearchTree::remove(TreeNode *root, int v) {
    if (root != nullptr)
        return root;
    if (root->value() == v) {
        if (root->leftSubtree() != nullptr && root->rightSubtree() != nullptr) {
            root->value() = lowerNum(root->rightSubtree());
            root->rightSubtree(remove(root->rightSubtree(), root->value()));
        }
        else {
            TreeNode* newNode;
            if (root->rightSubtree() == nullptr)
                newNode = root->rightSubtree();
            else
                newNode = root->leftSubtree();
            delete(root);
            root = newNode;
        }
    }
    else if (root->value() < v)
        root->rightSubtree(remove(root->rightSubtree(), v));
    else
        root->leftSubtree(remove(root->leftSubtree(), v));
    return root;
}



int BinSearchTree::lowerNum(TreeNode *root) {
    while (root->leftSubtree() != nullptr)
        root = root->leftSubtree();
    return root->value();
}


int BinSearchTree::kthSmallest(int k) {
    int counter = 0;
    return kthSmallest(root, k, &counter);
}

int BinSearchTree::kthSmallest(TreeNode *root, int k, int *counter) {
    if (root == nullptr)
        return 0;
    int L = kthSmallest(root->leftSubtree(), k, counter);
    if ( L != 0)
        return L;
    if (++*counter == k)
        return root->value();
    return kthSmallest(root->rightSubtree(), k, counter);
}

void BinSearchTree::valuesAtLevel(int k) {
    return valuesAtLevel(root, k);
}

void BinSearchTree::valuesAtLevel(TreeNode *root, int k) {
    if (root == nullptr)
        return;
    if (k == 1) {
        std::cout << root->value() << std::endl;
        return;
    }
    if (root->leftSubtree() != nullptr)
        valuesAtLevel(root->leftSubtree(), k-1);
    if (root->rightSubtree() != nullptr)
        valuesAtLevel(root->rightSubtree(), k-1);
}

void BinSearchTree::iterValuesAtLevel(int k) {
    return iterValuesAtLevel(root, k);
}

void BinSearchTree::iterValuesAtLevel(TreeNode *root, int k) {
    std::queue<TreeNode *> q;
    int level = 1;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TreeNode *newNode = q.front();

        if (level == k && newNode != nullptr)
            std::cout << newNode->value() << std::endl;
        q.pop();

        if (newNode == nullptr) {
            if (q.front())
                q.push(nullptr);
            level++;
        }
        else {
            if (newNode->leftSubtree())
                q.push(newNode->leftSubtree());
            if (newNode->rightSubtree())
                q.push(newNode->rightSubtree());
        }
    }
}

int BinSearchTree::iterMaxDepth() {
    return iterMaxDepth(root);
}

int BinSearchTree::iterMaxDepth(TreeNode *root) {
    if (root == nullptr)
        return 0;

    std::queue<TreeNode *> q;
    q.push(root);

    int h = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size > 0) {
            TreeNode *newRoot = q.front();
            q.pop();
            if (newRoot->leftSubtree())
                q.push(newRoot->leftSubtree());
            if (newRoot->rightSubtree())
                q.push(newRoot->rightSubtree());
            size--;
        }
        h++;
    }
    return h;
}

bool BinSearchTree::hasRootToLeafSum(int sum) {
    if (local_hasRootToLeaf(root, sum, 0))
        return true;
    return false;
}

bool BinSearchTree::local_hasRootToLeaf(TreeNode *root, int sum, int totalSum) {
    if (root == nullptr)
        return false;
    int count = root->value();
    totalSum = count + totalSum;

    if (totalSum == sum) {
        if (root->leftSubtree() == nullptr && root->rightSubtree() == nullptr)
            return true;
    }
    if (local_hasRootToLeaf(root->leftSubtree(), sum, totalSum))
        return true;
    else if (local_hasRootToLeaf(root->rightSubtree(), sum, totalSum))
        return true;
    return false;
}

bool BinSearchTree::areIdentical(BinSearchTree *bst) {
    TreeNode *root2 = bst->root;
    return areIdentical(root, root2);
}

bool BinSearchTree::areIdentical(TreeNode *root, TreeNode *root2) {
    if (root == nullptr && root2 == nullptr)
        return true;
    else if (root != nullptr && root2 == nullptr)
        return false;
    else if (root == nullptr && root2 != nullptr)
        return false;
    else {
        return (areIdentical(root->leftSubtree(), root2->leftSubtree()) &&
                areIdentical(root->rightSubtree(), root2->rightSubtree()));
    }
}

void BinSearchTree::intersectWith(TreeNode *root, BinSearchTree *bst, BinSearchTree *newTree) {
    if (root == nullptr || bst == nullptr)
        return;
    if (bst->find(root->value())){
        newTree->m(root->value());
    }
    intersectWith(root->leftSubtree(), bst, newTree);
    intersectWith(root->rightSubtree(), bst, newTree);
}

BinSearchTree *BinSearchTree::intersectWith( BinSearchTree *bst ) {
    BinSearchTree *newTree = new BinSearchTree();
    intersectWith(root, bst, newTree);
    return newTree;
}

BinSearchTree *BinSearchTree::unionWith( BinSearchTree *bst) {
    BinSearchTree *newTree = bst;
    unionWith(root, newTree);
    return newTree;
}

void BinSearchTree:: unionWith(TreeNode *root, BinSearchTree *newTree) {
    if (root == nullptr)
        return;
    if (newTree->find(root->value())) {
        unionWith(root->leftSubtree(), newTree);
        unionWith(root->rightSubtree(), newTree);
    }
    else {
        newTree->insert(root->value());
        unionWith(root->leftSubtree(), newTree);
        unionWith(root->rightSubtree(), newTree);
    }
}

BinSearchTree *BinSearchTree::differenceOf( BinSearchTree *bst) {
    BinSearchTree *newTree = new BinSearchTree();
    differenceOf(root, bst, newTree);
    differenceOf(bst->root, this, newTree);
    return newTree;
}
void BinSearchTree::differenceOf(TreeNode *root, BinSearchTree *bst, BinSearchTree *newTree) {
    if (root == nullptr)
        return;
    if (!bst->find(root->value())) {
        newTree->insert(root->value());
    }
    differenceOf(root->leftSubtree(), bst, newTree);
    differenceOf(root->rightSubtree(), bst, newTree);

}

