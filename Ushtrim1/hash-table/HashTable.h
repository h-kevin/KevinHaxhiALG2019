// Header class to handle operations with the HashTable.

class HashTable {

private:

    struct *node {

        string data;
        int key;
        node *next;
    }

    node *hTable[2019];
    int counter;

public:

    HashTable();

    int getNodesNum();

    int getStringSum(string w);

    void add(string w);

    void remove();

    void find(string w);

    void print();
} // end header class HashTable