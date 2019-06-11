// Header class to handle operations with the balanced binary tree.

class BalancedBinaryTree {

private:

    struct treeNode {

        string data;
        treeNode *left, *right;
        int height;
    };

    treeNode *root;
    int counter;

public:

    BalancedBinaryTree();

    treeNode* getRoot();

    int getNodesNumber();

    treeNode* findMin(treeNode *r);

    int getMax(int a, int b);

    int getHeight(treeNode *n);

    treeNode* rightRotate(treeNode *y);

    treeNode* leftRotate(treeNode *x);

    int getBalance (treeNode *n);

    void add(treeNode* r = this->root, string w);

    treeNode* Delete(treeNode *r = this->root, string w);

    void remove(string w);

    bool find(string w);

    void print(treeNode *r = this->root, int c = 1);
} // end header class BalancedBinaryTree