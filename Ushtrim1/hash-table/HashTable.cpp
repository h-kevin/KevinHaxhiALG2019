// Class to handle operations with the HashTable.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node1 {

public:

    string data;
    int key;
    node1 *next;
};

class HashTable {

private:

    node1 *hTable[2019];
    int counter;

public:

    HashTable() {

        for (int i = 0; i < 2019; i++) {

            this->hTable[i] = NULL;
        }
    
        this->counter = 0;
    }

    int getNodesNumber() {
        
        return this->counter;
    }

    int getStringSum(string w) {

        int s = 0;

        for (int i = 0; i < w.length(); i++) {

            s += (int) w.at(i);
        }

        return s;
    }

    void add(string w) {

        transform(w.begin(), w.end(), w.begin(), ::tolower);

        node1 *tmp = new node1;
        tmp->data = w;
        tmp->key = getStringSum(w);
        tmp->next = NULL;
        this->counter++;

        if (this->hTable[tmp->key % 2019] == NULL) {

            this->hTable[tmp->key % 2019] = tmp;
        } else {

            tmp->next = this->hTable[tmp->key % 2019];
            this->hTable[tmp->key % 2019] = tmp;
        }
    }

    void remove(string w) {

        int key = getStringSum(w);
        node1 *tmp = this->hTable[key % 2019];
        node1 *p;

        while (tmp != NULL && tmp->data != w) {

            p = tmp;
            tmp = tmp->next;
        }

        if (tmp == NULL)
            return;
        else {

            node1 *nextEntry = tmp->next;
            if (p != NULL) {

                p->next = nextEntry;
                tmp = NULL;
                this->counter--;
            }
            else {

                if (nextEntry == NULL) {

                    this->hTable[key % 2019] = NULL;
                    tmp = NULL;
                    this->counter--;
                } else {

                    this->hTable[key % 2019] = nextEntry;
                    tmp = NULL;
                    this->counter--;
                }
            }
        }
    }

    bool find(string w) {

        int key = getStringSum(w);
        node1 *tmp = this->hTable[key % 2019];

        while (tmp != NULL && tmp->data != w) {

            tmp = tmp->next;
        }

        if (tmp == NULL)
            return false;
        else
            return true;
    }

    void print() {

        for (int i = 0; i < 2019; i++) {

            node1 *tmp = this->hTable[i];

            if (tmp != NULL)
                cout << endl;
    
            while (tmp != NULL) {
    
                cout << tmp->key << " " << tmp->data;
                if (tmp->next != NULL)
                    cout << " | ";

                tmp = tmp->next;
            }
        }
    }
}; // end class HashTable