// Header class to handle operations with the HashTable.

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

class node {

public:

    string data;
    int key;
    node *next;
};

class HashTable {

private:

    node *hTable[2019];
    int counter;

public:

    HashTable();

    int getNodesNum();

    int getStringSum(string w);

    void add(string w);

    void remove(string w);

    bool find(string w);

    void print();
}; // end header class HashTable
#endif