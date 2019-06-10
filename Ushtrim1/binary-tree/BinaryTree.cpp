// Class to handle operations with the binary tree.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct treeNode {

    string data;
    treeNode *left, *right;
};

class BinaryTree {

private:

    treeNode *root;
    int counter;

public:

    BinaryTree() {

        this->root = NULL;
        this->counter = 0;
    }

    void add(treeNode* r = this->root, string w) {

        if (r == NULL) {

            transform(w.begin(), w.end(), w.begin(), ::tolower);

            treeNode *tmp = new treeNode;
            tmp->data = w;
            tmp->left = tmp->right = NULL;
            this->counter++;
        } else if (w.compare(r->data) < 0) {

            add(r->left, w);
        } else if (w.compare(r->data) > 0) {

            add(r->right, w);
        }
    }

    
}