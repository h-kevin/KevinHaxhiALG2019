// Header class to handle operations with the binary tree.

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using namespace std;

class treeNode {

public:
     
    string data;
    treeNode *left, *right;
};

class BinaryTree {

private:

    static treeNode *root;
    int counter;

public:

    BinaryTree();

    treeNode* getRoot();

    int getNodesNumber();

    void add(string w, treeNode *r = root);

    treeNode* findMin(treeNode *r);

    treeNode* Delete(string w, treeNode *r = root);

    void remove(string w);

    bool find(string w);

    void print(int c = 1, treeNode *r = root);
}; // end header class BinaryTree
#endif