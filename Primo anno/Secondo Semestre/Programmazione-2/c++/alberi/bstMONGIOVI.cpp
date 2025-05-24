#include <iostream>

using namespace std;

class BST;

class BSTNode 
{
public:
    int getVal() const;
private:
    int val;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
    friend class BST;
};

class BST
{
public:
    BST() : root(nullptr) {}
    ~BST();
    BST& Insert(int val);
    void Print();
private:
    void Print(BSTNode* node);
    void Delete(BSTNode* node);
    BSTNode* root;
};

int main() {
    BST albero;
    albero.Insert(10);
    albero.Print();
    albero.Insert(13);
    albero.Print();
    albero.Insert(5);
    albero.Print();
    albero.Insert(6);
    albero.Print();
    albero.Insert(12);
    albero.Print();
    return 0;
}

BST& BST::Insert(int val)
{
    BSTNode* x = root;
    BSTNode* y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    BSTNode* node = new BSTNode;
    node->val = val;
    node->parent = y;
    node->left = nullptr;
    node->right = nullptr;
    if (y == nullptr)
        root = node;
    else if (val < y->val)
        y->left = node;
    else
        y->right = node;
    return *this;
}

void BST::Print()
{
    Print(root);
    cout << endl;
}

void BST::Print(BSTNode* node)
{
    if (node)
    {
        cout << "this: " << node << " val: " << node->val << " parent: " << node->parent << " left: " << node->left << " right: " << node->right << endl;
        Print(node->left);
        Print(node->right);
    }
}

BST::~BST()
{
    Delete(root);
}

void BST::Delete(BSTNode* node)
{
    if (node)
    {
        Delete(node->left);
        Delete(node->right);
        delete node;
    }
}