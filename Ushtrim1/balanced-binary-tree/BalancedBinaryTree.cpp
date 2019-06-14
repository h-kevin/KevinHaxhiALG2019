// Class to handle operations with the balanced binary tree.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class treeNode1 {

public:
     
    string data;
    treeNode1 *left, *right;
    int height;

    treeNode1(string w) {

        this->data = w;
        this->left = NULL;
        this->right = NULL;
        int height = 1;
    }
};

class BalancedBinaryTree {

private:

    treeNode1 *root;
    int counter;
    int pCounter = 0;

    treeNode1* findMin(treeNode1 *root) {

        while (root->left != NULL)
        root = root->left;
    
        return root;
    }

    treeNode1* rr_rotation(treeNode1 *parent) {

        treeNode1 *t;

        t = parent->right;
        parent->right = t->left;
        t->left = parent;

        return t;
    }

    treeNode1* ll_rotation(treeNode1 *parent) {

        treeNode1 *t;

        t = parent->left;
        parent->left = t->right;
        t->right = parent;

        return t;
    }

    treeNode1* rl_rotation(treeNode1 *parent) {

        treeNode1 *t;
        t = parent->right;
        parent->right = ll_rotation(t);
        return rr_rotation(parent);
    }

    treeNode1* lr_rotation(treeNode1 *parent) {

        treeNode1 *t;
        t = parent->left;
        parent->left = rr_rotation(t);
        return ll_rotation(parent);
    }

    int getMax(int a, int b) {

        return (a > b) ? a : b;
    }

    int getHeight(treeNode1 *root) {

        int h = 0;

        if (root) {

            int lHeight = getHeight(root->left);

            int rHeight = getHeight(root->right);

            int maxHeight = getMax(lHeight, rHeight);

            h = maxHeight  +1;
        }

        return h;
    }

    int getDiff(treeNode1 *root) {

        int lHeight = getHeight(root->left);

        int rHeight = getHeight(root->right);

        return lHeight - rHeight;
    }

    treeNode1* getBalance (treeNode1 *root) {

        int balanceFactor = getDiff(root);

        if (balanceFactor > 1) {

            if (getDiff(root->left) > 0)
                root = ll_rotation(root);
            else
                root = lr_rotation(root);
        } else if (balanceFactor < -1) {

            if (getDiff(root->right) < 0)
                root = rr_rotation(root);
            else
                root = rl_rotation(root);
        }

        return root;
    }

    treeNode1* addHelper(treeNode1 *root, string w) {
        
        if (root == NULL) {

           root = new treeNode1(w);
           this->counter++;
           return root;
        } else if (w.compare(root->data) < 0) {

           root->left = addHelper(root->left, w);
           root = getBalance(root);
        } else if (w.compare(root->data) > 0) {

           root->right = addHelper(root->right, w);
           root = getBalance(root);
        } 
        
        return root;
     }

    treeNode1* removeHelper(treeNode1 *root, string w) {

        if (root == NULL)
            return NULL;

        else if (w.compare(root->data) < 0) {
            root->left = removeHelper(root->left, w); // searching recursively on the left
            root = getBalance(root);
        }

        else if (w.compare(root->data) > 0) { 
            root->right = removeHelper(root->right, w); // searching recursively on the right
            root = getBalance(root);
        }

        else { // treeNode to remove was found

            // Case 1: our treeNode has no child
            if (root->left == NULL && root->right == NULL) {

                delete root;
                root = NULL;
                this->counter--;
            }
            // Case 2: our treeNode has one child (left or right)
            else if (root->left == NULL) {

                treeNode1 *tmp = root;
                root = root->right;
                delete tmp;
                this->counter--;
            }
            else if (root->right == NULL) {

                treeNode1 *tmp = root;
                root = root->left;
                delete tmp;
                this->counter--;
            }
            // Case 3: our treeNode has 2 children (left and right)
            else {

                treeNode1 *tmp = findMin(root->right); // left tree < r < tmp < right tree
                root->data = tmp->data; // r data is reinitialized with tmp's data
                root->right = removeHelper(root->right, tmp->data); // removing the original treeNode that became r
                this->counter--;
            }
        }

        return root;
    }

    bool findHelper(treeNode1 *root, string w) {

        if (root == NULL)
            return false;
        else if (w == root->data)
            return true;
        else if (w.compare(root->data) < 0)
            return findHelper(root->left, w);
        else
            return findHelper(root->right, w);
    }

    void printHelper(treeNode1 *root) {

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

    BalancedBinaryTree() {

        this->root = NULL;
        this->counter = 0;
    }

    treeNode1* getRoot() {

        return this->root;
    }

    int getNodesNumber() {

        return this->counter;
    }

    void add(string w) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);
        
        if (this->root) {

            this->root = this->addHelper(this->root, w);
        } else {

            this->root = new treeNode1(w);
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
}; // end class BalancedBinaryTree