// Class to handle singly linked list operations.

#include <string>
#include <iostream>

using namespace std;

struct node {

    string data;
    node *next;
}

class SinglyLinkedList {

private:

    node *head, *tail;

public:

    SinglyLinkedList() {

        this->head = NULL;
        this->tail = NULL;
    }

    void add(string w) {

        node *tmp = new node;
        tmp->data = w;
        tmp->next = w;

        if (this->head == NULL && this->tail == NULL) {

            this->head = tmp;
            this->tail = tmp;
        } else {

            this->tail->next = tmp;
            this->tail = this->tail->next;
        }
    }

    string remove(string w) {

        node *tmp = this->head;
        node *p;
        string d;

        while (tmp != NULL) {

            if (tmp->data == w) {
                
                if (tmp == this->head) {

                    d = tmp->data;
                    this->head = this->head->next;
                    tmp = NULL;
                    return d;
                } else {

                    d = tmp->data;
                    p->next = tmp->next;
                    tmp = NULL;
                    return d;
                }
            }

            p = tmp;
            tmp = tmp->next;
        }

        return NULL;
    }
}