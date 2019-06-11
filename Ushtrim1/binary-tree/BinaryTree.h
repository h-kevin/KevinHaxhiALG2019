// Header class to handle operations with the binary tree.

class BinaryTree {

private:

    struct treeNode {

        string data;
        treeNode *left, *right;
    };

    treeNode *root;
    int counter;

public:

    BinaryTree();

    treeNode* getRoot();

    int getNodesNumber();

    void add(treeNode* r = this->root, string w);

    treeNode* findMin(treeNode *r);

    treeNode* Delete(treeNode *r = this->root, string w);

    void remove(string w);

    bool find(string w);

    void print(treeNode *r = this->root, int c = 1);
} // end header class BinaryTree