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
};

class BalancedBinaryTree {

private:

    treeNode1 *root;
    int counter;

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

    treeNode1* findMin(treeNode1 *r) {

        while (r->left != NULL)
        r = r->left;
    
        return r;
    }

    int getMax(int a, int b) {

        return (a > b) ? a : b;
    }

    int getHeight(treeNode1 *n) {

        if (n == NULL)
        return 0;
    
        return n->height;
    }

    treeNode1* rightRotate(treeNode1 *y) {

        treeNode1 *x = y->left;
        treeNode1 *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    treeNode1* leftRotate(treeNode1 *x) {

        treeNode1 *y = x->right;
        treeNode1 *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    int getBalance (treeNode1 *n) {

        if (n == NULL)
        return 0;

        return getHeight(n->left) - getHeight(n->right);
    }

    treeNode1* Insert(string w, treeNode1* r) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);

        if (r == NULL) {

            treeNode1 *tmp = new treeNode1;
            tmp->data = w;
            tmp->left = tmp->right = NULL;
            tmp->height = 1;
            this->counter++;
            return tmp;
        } else if (w.compare(r->data) < 0) {

            return Insert(w, r->left);
        } else if (w.compare(r->data) > 0) {

            return Insert(w, r->right);
        }

        r->height = 1 + getMax(getHeight(r->left), getHeight(r->right));

        int balance = getBalance(r);

        // Left Left Case
        if (balance > 1 && w.compare(r->left->data) < 0) {

            return rightRotate(r);
        }
        
        // Right Right Case
        if (balance < -1 && w.compare(r->right->data) > 0) {

            return leftRotate(r);
        }

        // Left Right Case
        if (balance > 1 && w.compare(r->left->data) > 0) {

            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case
        if (balance < -1 && w.compare(r->right->data) < 0) {

            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    void add(string w) {

        this->root = Insert(w, this->root);
    }

    treeNode1* Delete(string w, treeNode1 *r) {

        if (r == NULL)
        
        return NULL; // no elements
        else if (w.compare(r->data) < 0)
            
            r->left = Delete(w, r->left); // searching recursively on the left
        else if (w.compare(r->data) > 0)
                
            r->right = Delete(w, r->right); // searching recursively on the right
        else { // treeNode1 to remove was found

            // Case 1: our treeNode1 has no child
            if (r->left == NULL && r->right == NULL) {

                delete r;
                r = NULL;
                this->counter--;
            }
            // Case 2: our treeNode1 has one child (left or right)
            else if (r->left == NULL) {

                treeNode1 *tmp = r;
                r = r->right;
                delete tmp;
                this->counter--;
            }
            else if (r->right == NULL) {

                treeNode1 *tmp = r;
                r = r->left;
                delete tmp;
                this->counter--;
            }
            // Case 3: our treeNode1 has 2 children (left and right)
            else {

                treeNode1 *tmp = findMin(r->right); // left tree < r < tmp < right tree
                r->data = tmp->data; // r data is reinitialized with tmp's data
                r->right = Delete(tmp->data, r->right); // removing the original treeNode1 that became r
                this->counter--;
            }
        }

        return r;
    }

    void remove(string w) { // simplified removal with void function using the above algorythm

        this->root = Delete(w, this->root);
    }

    bool find(string w) {

        treeNode1 *current = this->root;
    
        while (current != NULL) {
    
            if (w.compare(current->data) < 0)
                current = current->left;
            else if (w.compare(current->data) > 0)
                current = current->right;
            else
                return true;
        }
    
        return false;
    }

    void print(treeNode1 *r, int c = 1) {

        if (r == NULL) {
    
            cout << "NULL";
            return;
        }
    
        print(r->left, c);
        c++;
        
        cout << r->data;
        
        if (c % 5 == 0)
            cout << endl;
        else
            cout << " , ";
    
        print(r->right, c);
    }
}; // end class BalancedBinaryTree