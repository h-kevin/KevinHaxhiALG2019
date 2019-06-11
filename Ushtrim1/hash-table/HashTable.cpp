// Class to handle operations with the HashTable.

#include <string>
#include <iostream>
#include <bits/stdc++.h>

#include "HashTable.h"

using namespace std;

HashTable :: HashTable() {

    for (int i = 0; i < 2019; i++) {

        this->hTable[i] = NULL;
    }

    this->counter = 0;
}

int HashTable :: getNodesNum() {

    return this->counter;
}

int HashTable :: getStringSum(string w) {

    int s = 0;

    for (int i = 0; i < w.length(); i++) {

        s += (int) w.at(i);
    }

    return s;
}

void HashTable :: add(string w) {

    transform(w.begin(), w.end(), w.begin(), ::tolower);

    node *tmp = new node;
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

void HashTable :: remove(string w) {

    int key = getStringSum(w);
    node *tmp = this->hTable[key % 2019];

    while (tmp != NULL && tmp->data != w) {

        tmp = tmp->next;
    }

    if (tmp == NULL)
        return;
    else {

        node *toDelete = tmp;
        tmp = tmp->next;
        delete(tmp);
    }
}

bool HashTable :: find(string w) {

    int key = getStringSum(w);
    node *tmp = this->hTable[key % 2019];

    while (tmp != NULL && tmp->data != w) {

        tmp = tmp->next;
    }

    if (tmp == NULL)
        return false;
    else
        return true;
}

void HashTable :: print() {

    for (int i = 0; i < 2019; i++) {

        node *tmp = this->hTable[i];

        while (tmp != NULL) {

            cout << tmp->key << " " << tmp->data << endl;
        }

        cout << endl;
    }
}