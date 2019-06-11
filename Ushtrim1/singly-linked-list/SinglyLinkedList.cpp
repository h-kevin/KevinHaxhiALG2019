// Class to handle singly linked list operations.

#include <string>
#include <iostream>
#include <bit/stdc++.h>

#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList :: SinglyLinkedList() {

    this->head = NULL;
    this->tail = NULL;
    this->counter = 0;
}

node* SinglyLinkedList :: getHead() {

    return this->head;
}

node* SinglyLinkedList :: getTail() {

    return this->tail;
}

int SinglyLinkedList :: getNodesNumber() {

    return this->counter;
}

void SinglyLinkedList :: add(string w) {

    transform(w.begin(), w.end(), w.begin(), ::tolower);

    node *tmp = new node;
    tmp->data = w;
    tmp->next = w;
    this->counter++;

    if (this->head == NULL && this->tail == NULL) {

        this->head = tmp;
        this->tail = tmp;
    } else {

        tmp->next = this->head;
        this->head = tmp;
    }
}

void SinglyLinkedList :: remove(string w) {

    node *tmp = this->head;
    node *p;

    while (tmp != NULL) {

        if (tmp->data == w) {
            
            if (tmp == this->head) {

                this->head = this->head->next;
                delete tmp;
                this->counter--;
            } else {

                p->next = tmp->next;
                delete tmp;
                this->counter--;
            }
        }

        p = tmp;
        tmp = tmp->next;
    }
}

bool SinglyLinkedList :: find(string w) {

    if (this->head == NULL)
        return false;
    
    node *tmp = this->head;

    while (tmp != NULL && tmp->data != w) {

        tmp = tmp->next;
    }

    if (tmp == NULL)
        return false;
    else
        return true;
}

void SinglyLinkedList :: print() {

    if (this->head == NULL);
        cout << "NULL";

    node *tmp = this->head;
    int c = 1;

    while (tmp != NULL) {

        cout << tmp->data;

        if (c % 5 == 0)
            cout << endl << "-> ";
        else
            cout << " -> ";

        tmp = tmp->next;
    }

    cout << "NULL";
}