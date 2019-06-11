// Class to handle operations with the binary tree.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

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

    void add(string w, treeNode *r = root) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);

        if (r == NULL) {

            treeNode *tmp = new treeNode;
            tmp->data = w;
            tmp->left = tmp->right = NULL;
            this->counter++;
            r = tmp;
        } else if (w.compare(r->data) < 0) {

            add(w, r->left);
        } else if (w.compare(r->data) > 0) {

            add(w, r->right);
        }
    }

    treeNode* findMin(treeNode *r) {

        while (r->left != NULL)
        r = r->left;
        
        return r;
    }

    treeNode* Delete(string w, treeNode *r = root) {

        if (r == NULL)
        
        return NULL; // no elements
        else if (w.compare(r->data) < 0)
            
            r->left = Delete(w, r->left); // searching recursively on the left
        else if (w.compare(r->data) > 0)
                
            r->right = Delete(w, r->right); // searching recursively on the right
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
                r->right = Delete(tmp->data, r->right); // removing the original treeNode that became r
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

    void print(int c = 1, treeNode *r = root) {

        if (r == NULL) {

            cout << "NULL";
            return;
        }
    
        print(c, r->left);
        
        cout << r->data;
        c++;
        
        if (c % 5 == 0)
            cout << endl;
        else
            cout << " , ";
    
        print(c, r->right);
    }
}; // end class BinaryTree