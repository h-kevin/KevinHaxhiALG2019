// Class to handle operations with the balanced binary tree.

#include <string>
#include <iostream>
#include <bit/stdc++.h>

using namespace std;

struct treeNode {

    string data;
    treeNode *left, *right;
    int height;
};

class BalancedBinaryTree {

private:

    treeNode *root;
    int counter;

public:

    BalancedBinaryTree() {

        this->root = NULL;
        this->counter = 0;
    }

    treeNode* getRoot() {

        return this->root;
    }

    int getNodesNumber() {

        return this->counter;
    }

    treeNode* findMin(treeNode *r) {

        while (r->left != NULL)
            r = r->left;
        
        return r;
    }

    int getMax(int a, int b) {

        return (a > b) ? a : b;
    }

    int getHeight(treeNode *n) {

        if (n == NULL)
            return 0;
        
        return n->height;
    }

    treeNode* rightRotate(treeNode *y) {

        treeNode *x = y->left;
        treeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    treeNode* leftRotate(treeNode *x) {

        treeNode *y = x->right;
        treeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    int getBalance (treeNode *n) {

        if (n == NULL)
            return 0;

        return getHeight(n->left) - getHeight(n->right);
    }

    void add(treeNode* r = this->root, string w) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);

        if (r == NULL) {

            treeNode *tmp = new treeNode;
            tmp->data = w;
            tmp->left = tmp->right = NULL;
            tmp->height = 1;
            r = tmp;
            this->counter++;
        } else if (w.compare(r->data) < 0) {

            add(r->left, w);
        } else if (w.compare(r->data) > 0) {

            add(r->right, w);
        }

        r->height = 1 + getMax(getHeight(r->left), getHeight(r->right));

        int balance = getBalance(r);

        // Left Left Case
        if (balance > 1 && w.compare(r->left->data) < 0) {

            r = rightRotate(r);
            return;
        }
        
        // Right Right Case
        if (balance < -1 && w.compare(r->right->data) > 0) {

            r = leftRotate(r);
            return;
        }

        // Left Right Case
        if (balance > 1 && w.compare(r->left->data) > 0) {

            r->left = leftRotate(r->left);
            r = rightRotate(r);
            return;
        }

        // Right Left Case
        if (balance < -1 && w.compare(r->right->data) < 0) {

            r->right = rightRotate(r->right);
            r = leftRotate(r);
            return;
        }
    }

    treeNode* Delete(treeNode *r = this->root, string w) {

        if (r == NULL)
            
            return NULL; // no elements
        else if (w.compare(r->data) < 0)
            
            r->left = Delete(r->left, w); // searching recursively on the left
        else if (w.compare(r->data) > 0)
                
            r->right = Delete(r->right, w); // searching recursively on the right
        else { // treeNode to remove was found

            // Case 1: our treeNode has no child
            if (r->left == NULL && r->right == NULL) {

                delete r;
                r = NULL;
                this->counter--;
            }
            // Case 2: our treeNode has one child (left or right)
            else if (r->left == NULL) {

                treeNode *tmp = r;
                r = r->right;
                delete tmp;
                this->counter--;
            }
            else if (r->right == NULL) {

                treeNode *tmp = r;
                r = r->left;
                delete tmp;
                this->counter--;
            }
            // Case 3: our treeNode has 2 children (left and right)
            else {

                treeNode *tmp = findMin(r->right); // left tree < r < tmp < right tree
                r->data = tmp->data; // r data is reinitialized with tmp's data
                r->right = Delete(r->right, tmp->data); // removing the original treeNode that became r
                this->counter--;
            }
        }

        return r;
    }

    void remove(string w) { // simplified removal with void function using the above algorythm

        this->root = Delete(w);
    }

    bool find(string w) {

        treeNode *current = this->root;

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

    void print(treeNode *r = this->root, int c = 1) {

        if (r == NULL) {

            cout << "NULL";
            return;
        }

        print(r->left);
        
        cout << r->data;
        
        if (c % 5 == 0)
            cout << endl;
        else
            cout << " , ";

        print(r->right);
    }
} // end class BalancedBinaryTree