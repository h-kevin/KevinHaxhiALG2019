// Program with main function.

#include <string>
#include <iostream>
#include <time.h>
#include <iostream>
#include <fstream>

#include "singly-linked-list/SinglyLinkedList.h"
#include "binary-tree/BinaryTree.h"
#include "balanced-binary-tree/BalancedBinaryTree.h"
#include "hash-table/HashTable.h"

using namespace std;

void readAndStore(int c1, int c2, SinglyLinkedList l, BinaryTree t, BalancedBinaryTree bt, HashTable ht) {

    fstream in;

    in.open("data/file.txt");

    if (!in.is_open()) {

        cout << "The file failed to open ..." << endl << endl;
        exit(EXIT_FAILURE);
    } else {

        string w;

        if (c1 == 1) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!l.find(w))
                    l.add(w);
            }
        } else if (c1 == 2) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!t.find(w))
                    t.add(w);
            }
        }
    }
}

int main() {

    int ch1 = 1;
    int ch2 = 1;

    SinglyLinkedList list;
    BinaryTree tree;
    BalancedBinaryTree balancedTree;
    HashTable hTable;

    if (system("CLS")) system("clear");

    cout << "Choose a method to implement the dictionary:" << endl << endl;
    cout << "1. Singly Linked List" << endl;
    cout << "2. Binary Tree" << endl;
    cout << "3. Balanced Binary Tree" << endl;
    cout << "4. Hash Table (chaining method)" << endl;
    cout << "5. Exit the program ...";

    while (ch1 > 5 || ch1 < 1) {

        cout << endl << endl << "Enter your choice: ";
        cin >> ch1;
    }

    if (system("CLS")) system("clear");

    cout << "Choose the number of words to initiate the algorythm:" << endl << endl;
    cout << "1. 100 words" << endl;
    cout << "2. 1,000 words" << endl;
    cout << "3. 100,000 words" << endl;
    cout << "4. 1,000,000 words" << endl;
    cout << "5. Exit the program ...";

    while (ch2 > 5 || ch2 < 1) {

        cout << endl << endl << "Enter your choice: ";
        cin >> ch2;
    }

    if (ch2 == 5)
        exit(EXIT_SUCCESS);

    switch (ch1)
    {
        case 1:
            if (system("CLS")) system("clear");
            readAndStore(1, ch2, list, tree, balancedTree, hTable);
            break;

        case 2:
            if (system("CLS")) system("clear");
            readAndStore(2, ch2, list, tree, balancedTree, hTable);
            break;

        case 3:
            if (system("CLS")) system("clear");
            readAndStore(3, ch2, list, tree, balancedTree, hTable);
            break;

        case 4:
            if (system("CLS")) system("clear");
            readAndStore(4, ch2, list, tree, balancedTree, hTable);
            break;
        
        case 5:
            cout << endl << endl;
            exit(EXIT_SUCCESS);
    }

    return 0;
}