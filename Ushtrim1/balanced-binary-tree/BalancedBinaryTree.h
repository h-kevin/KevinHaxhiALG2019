// Header class to handle operations with the balanced binary tree.

#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H

#include <string>

using namespace std;

class treeNode {

public:

    string data;
    treeNode *left, *right;
    int height;
};

class BalancedBinaryTree {

private:

    static treeNode *root;
    int counter;

public:

    BalancedBinaryTree();

    treeNode* getRoot();

    int getNodesNumber();

    treeNode* findMin(treeNode *r);

    int getMax(int a, int b);

    int getHeight(treeNode *n);

    treeNode* rightRotate(treeNode *y);

    treeNode* leftRotate(treeNode *x);

    int getBalance (treeNode *n);

    void add(string w, treeNode* r = root);

    treeNode* Delete(string w, treeNode *r = root);

    void remove(string w);

    bool find(string w);

    void print(int c = 1, treeNode *r = root);
}; // end header class BalancedBinaryTree
#endif