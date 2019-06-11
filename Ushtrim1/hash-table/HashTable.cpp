// Class to handle operations with the HashTable.

#include <string>
#include <iostream>

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

    
}