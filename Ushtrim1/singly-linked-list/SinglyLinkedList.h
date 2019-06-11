// Header class to handle singly linked list operations.

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>

using namespace std;

class node {

public:

    string data;
    node *next;
};

class SinglyLinkedList {

private:

    node *head, *tail;
    int counter;

public:

    SinglyLinkedList();

    node* getHead();
    node* getTail();

    int getNodesNumber();

    void add(string w);

    void remove(string w);

    bool find(string w);

    void print();
}; // end header class SinglyLinkedList
#endif