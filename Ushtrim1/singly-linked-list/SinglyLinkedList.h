// Header class to handle singly linked list operations.

class SinglyLinkedList {

private:

    struct node {

        string data;
        node *next;
    };

    node *head, *tail;
    int counter;

public:

    SinglyLinkedList();

    node* getHead();
    node* getTail();

    int getNodesNumber();

    void add(string w);

    void remove();

    bool find(string w);

    void print();
} // end header class SinglyLinkedList