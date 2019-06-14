// Class to handle operations with the binary tree.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class treeNode {

public:
     
    string data;
    treeNode *left, *right;

    treeNode(string w) {

        this->data = w;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {

private:

    treeNode *root;
    int counter;
    int pCounter = 0;

    void addHelper(treeNode *root, string w) {

        if (w.compare(root->data) < 0) {

            if (!root->left) {

                root->left = new treeNode(w);
                this->counter++;
            } else {

                addHelper(root->left, w);
            }
        } else if (w.compare(root->data) > 0) {

            if (!root->right) {

                root->right = new treeNode(w);
                this->counter++;
            } else {

                addHelper(root->right, w);
            }
        }
    }

    treeNode* findMin(treeNode *root) {

        while (root->left != NULL)
        root = root->left;
        
        return root;
    }

    treeNode* removeHelper(treeNode *root, string w) {

        if (root == NULL)
            return NULL;

        else if (w.compare(root->data) < 0)
            root->left = removeHelper(root->left, w); // searching recursively on the left

        else if (w.compare(root->data) > 0) 
            root->right = removeHelper(root->right, w); // searching recursively on the right

        else { // treeNode to remove was found

            // Case 1: our treeNode has no child
            if (root->left == NULL && root->right == NULL) {

                delete root;
                root = NULL;
                this->counter--;
            }
            // Case 2: our treeNode has one child (left or right)
            else if (root->left == NULL) {

                treeNode *tmp = root;
                root = root->right;
                delete tmp;
                this->counter--;
            }
            else if (root->right == NULL) {

                treeNode *tmp = root;
                root = root->left;
                delete tmp;
                this->counter--;
            }
            // Case 3: our treeNode has 2 children (left and right)
            else {

                treeNode *tmp = findMin(root->right); // left tree < r < tmp < right tree
                root->data = tmp->data; // r data is reinitialized with tmp's data
                root->right = removeHelper(root->right, tmp->data); // removing the original treeNode that became r
                this->counter--;
            }
        }

        return root;
    }

    bool findHelper(treeNode *root, string w) {

        if (root == NULL)
            return false;
        else if (w == root->data)
            return true;
        else if (w.compare(root->data) < 0)
            return findHelper(root->left, w);
        else
            return findHelper(root->right, w);
    }

    void printHelper(treeNode *root) {

        if (!root)
            return;
        
        printHelper(root->left);
        
        cout << root->data;
        this->pCounter++;
        
        if (pCounter % 5 == 0)
            cout << endl;
        else
            cout << " , ";

        printHelper(root->right);
    }

public:

    BinaryTree() {

        this->root = NULL;
        this->counter = 0;
    }

    treeNode* getRoot() {

        return  this->root;
    }

    int getNodesNumber() {

        return this->counter;
    }

    void add(string w) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);
        
        if (this->root) {

            this->addHelper(this->root, w);
        } else {

            this->root = new treeNode(w);
            this->counter++;
        }
    }

    void remove(string w) {

        if (this->root) {

            this->root = this->removeHelper(this->root, w);
        }
    }

    bool find(string w) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);

        if (this->root) {

            return this->findHelper(this->root, w);
        }
    }

    void print() {

        if (this->root) {

            pCounter = 0;
            this->printHelper(this->root);
            cout << "NULL";
        } else {

            cout << "NULL";
        }
    }
}; // end class BinaryTree