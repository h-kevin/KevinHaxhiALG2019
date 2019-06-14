// Program with main function.

#include <string>
#include <iostream>
#include <chrono>
#include <fstream>

#include "singly-linked-list/SinglyLinkedList.cpp"
#include "binary-tree/BinaryTree.cpp"
#include "balanced-binary-tree/BalancedBinaryTree.cpp"
#include "hash-table/HashTable.cpp"

using namespace std;
using namespace std::chrono;

static int64_t lTime;
static int64_t tTime;
static int64_t btTime;
static int64_t htTime;

void readAndStore(int c1, int c2, SinglyLinkedList& l, BinaryTree& t, BalancedBinaryTree& bt, HashTable& ht) {

    ifstream in;

    in.open("data/file.txt");

    if (!in.is_open()) {

        cout << "The file failed to open ..." << endl << endl;
        exit(EXIT_FAILURE);
    } else {

        string w;
        high_resolution_clock::time_point t1;
        high_resolution_clock::time_point t2;

        if (c1 == 1) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!l.find(w)) {

                    t1 = high_resolution_clock::now();
                    l.add(w);
                    t2 = high_resolution_clock::now();
                }

                lTime += duration_cast<microseconds>( t2 - t1 ).count();
            }
        } else if (c1 == 2) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!t.find(w)) {

                    t1 = high_resolution_clock::now();
                    t.add(w);
                    t2 = high_resolution_clock::now();
                }

                tTime += duration_cast<microseconds>( t2 - t1 ).count();
            }
        } else if (c1 == 3) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!bt.find(w)) {

                    t1 = high_resolution_clock::now();
                    bt.add(w);
                    t2 = high_resolution_clock::now();
                }

                btTime += duration_cast<microseconds>( t2 - t1 ).count();
            }
        } else if (c1 == 4) {

            for (int i = 0; i < c2; i++) {

                in >> w;

                if (!ht.find(w)) {

                    t1 = high_resolution_clock::now();
                    ht.add(w);
                    t2 = high_resolution_clock::now();
                }

                htTime += duration_cast<microseconds>( t2 - t1 ).count();
            }
        }
    }

    in.close();
}

int main() {

    int ch1 = 0;
    int ch2 = 0;
    int ch3 = 0;

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

    if (ch1 == 5) {

        cout << endl << endl;
        exit(EXIT_SUCCESS);
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

    if (ch2 == 1)
        ch2 = 100;
    else if (ch2 == 2)
        ch2 = 1000;
    else if (ch2 == 3)
        ch2 = 100000;
    else if (ch2 == 4)
        ch2 = 1000000;
    else
        exit(EXIT_SUCCESS);

    switch (ch1)
    {
        case 1:
            if (system("CLS")) system("clear");
            cout << "Constructing the Singly Linked List with " << ch2 << " words ...";
            readAndStore(1, ch2, list, tree, balancedTree, hTable);
            cout << endl << endl << "Process took " << (double) lTime / 1000000 << " seconds execution time.";
            cout << endl << list.getNodesNumber() << " words were added.";
            cout << endl << "Press enter to continue ...";
            getchar();getchar();
            break;

        case 2:
            if (system("CLS")) system("clear");
            cout << "Constructing the Binary Tree with " << ch2 << " words ...";
            readAndStore(2, ch2, list, tree, balancedTree, hTable);
            cout << endl << endl << "Process took " << (double) tTime / 1000000 << " seconds execution time.";
            cout << endl << tree.getNodesNumber() << " words were added.";
            cout << endl << "Press enter to continue ...";
            getchar();getchar();
            break;

        case 3:
            if (system("CLS")) system("clear");
            cout << "Constructing the Balanced Binary Tree with " << ch2 << " words ...";
            readAndStore(3, ch2, list, tree, balancedTree, hTable);
            cout << endl << endl << "Process took " << (double) btTime / 1000000 << " seconds execution time.";
            cout << endl << balancedTree.getNodesNumber() << " words were added.";
            cout << endl << "Press enter to continue ...";
            getchar();getchar();
            break;

        case 4:
            if (system("CLS")) system("clear");
            cout << "Constructing the Hash Table with " << ch2 << " words ...";
            readAndStore(4, ch2, list, tree, balancedTree, hTable);
            cout << endl << endl << "Process took " << (double) htTime / 1000000 << " seconds execution time.";
            cout << endl << hTable.getNodesNumber() << " words were added.";
            cout << endl << "Press enter to continue ...";
            getchar();getchar();
            break;
    }

repeatAction:

    if (system("CLS")) system("clear");
    
    cout << "What action do you want to perform with the dictionary?" << endl << endl;
    cout << "1. Add a new word" << endl;
    cout << "2. Remove a certain word" << endl;
    cout << "3. Find a certain word" << endl;
    cout << "4. Print the dictionary" << endl;
    cout << "5. Exit the program ...";

    while (ch3 > 5 || ch3 < 1) {

        cout << endl << endl << "Enter your choice: ";
        cin >> ch3;
    }

    lTime = tTime = btTime = htTime = 0;
    string w;
    bool f;

    switch (ch3)
    {
        case 1:
            if (system("CLS")) system("clear");
            cout << "Type the word you want to add: ";
            cin >> w;
            if (list.getNodesNumber() != 0) {

                lTime = clock();
                list.add(w);
                lTime = clock() - lTime;
                cout << "Added, " << (double) lTime / 1000000 << " seconds.";
            } else if (tree.getNodesNumber() != 0) {

                tTime = clock();
                tree.add(w);
                tTime = clock() - tTime;
                cout << "Added, " << (double) tTime / 1000000 << " seconds.";
            } else if (balancedTree.getNodesNumber() != 0) {

                btTime = clock();
                balancedTree.add(w);
                btTime = clock() - btTime;
                cout << "Added, " << (double) btTime / 1000000 << " seconds.";
            } else {

                htTime = clock();
                hTable.add(w);
                htTime = clock() - htTime;
                cout << "Added, " << (double) htTime / 1000000 << " seconds.";
            }
            cout << endl << "Press enter to continue ...";
            ch3 = 0;
            getchar();getchar();
            goto repeatAction;
        
        case 2:
            if (system("CLS")) system("clear");
            cout << "Type the word you want to remove: ";
            cin >> w;
            if (list.getNodesNumber() != 0) {

                lTime = clock();
                list.remove(w);
                lTime = clock() - lTime;
                cout << "Removed, " << (double) lTime / 1000000 << " seconds.";
            } else if (tree.getNodesNumber() != 0) {

                tTime = clock();
                tree.remove(w);
                tTime = clock() - tTime;
                cout << "Removed, " << (double) tTime / 1000000 << " seconds.";
            } else if (balancedTree.getNodesNumber() != 0) {

                btTime = clock();
                balancedTree.remove(w);
                btTime = clock() - btTime;
                cout << "Removed, " << (double) btTime / 1000000 << " seconds.";
            } else {

                htTime = clock();
                hTable.remove(w);
                htTime = clock() - htTime;
                cout << "Removed, " << (double) htTime / 1000000 << " seconds.";
            }
            cout << endl << "Press enter to continue ...";
            ch3 = 0;
            getchar();getchar();
            goto repeatAction;;

        case 3:
            if (system("CLS")) system("clear");
            cout << "Type the word you want to find: ";
            cin >> w;
            if (list.getNodesNumber() != 0) {

                lTime = clock();
                f = list.find(w);
                lTime = clock() - lTime;
                if (f)
                    cout << "Found, " << (double) lTime / 1000000 << " seconds.";
                else
                    cout << "Not found, " << (double) lTime / 1000000 << " seconds.";
            } else if (tree.getNodesNumber() != 0) {

                tTime = clock();
                f = tree.find(w);
                tTime = clock() - tTime;
                if (f)
                    cout << "Found, " << (double) tTime / 1000000 << " seconds.";
                else
                    cout << "Not found, " << (double) tTime / 1000000 << " seconds.";
            } else if (balancedTree.getNodesNumber() != 0) {

                btTime = clock();
                f = balancedTree.find(w);
                btTime = clock() - btTime;
                if (f)
                    cout << "Found, " << (double) btTime / 1000000 << " seconds.";
                else
                    cout << "Not found, " << (double) btTime / 1000000 << " seconds.";
            } else {

                htTime = clock();
                f = hTable.find(w);
                htTime = clock() - htTime;
                if (f)
                    cout << "Found, " << (double) htTime / 1000000 << " seconds.";
                else
                    cout << "Not found, " << (double) htTime / 1000000 << " seconds.";
            }
            cout << endl << "Press enter to continue ...";
            ch3 = 0;
            getchar();getchar();
            goto repeatAction;

        case 4:
            if (system("CLS")) system("clear");
            cout << "The elements of the chosen dictionary:" << endl << endl;
            if (list.getNodesNumber() != 0) {

                lTime = clock();
                list.print();
                lTime = clock() - lTime;
                cout << endl << endl << "Elements were printed in " << (double) lTime / 1000000 << " seconds.";
            } else if (tree.getNodesNumber() != 0) {

                tTime = clock();
                tree.print();
                tTime = clock() - tTime;
                cout << endl << endl << "Elements were printed in " << (double) tTime / 1000000 << " seconds.";
            } else if (balancedTree.getNodesNumber() != 0) {

                btTime = clock();
                balancedTree.print();
                btTime = clock() - btTime;
                cout << endl << endl << "Elements were printed in " << (double) btTime / 1000000 << " seconds.";
            } else {

                htTime = clock();
                hTable.print();
                htTime = clock() - htTime;
                cout << endl << endl << "Elements were printed in " << (double) htTime / 1000000 << " seconds.";
            }
            cout << endl << "Press enter to continue ...";
            ch3 = 0;
            getchar();getchar();
            goto repeatAction;

        case 5:
            cout << endl << endl;
            exit(EXIT_SUCCESS);
    }

    return 0;
}