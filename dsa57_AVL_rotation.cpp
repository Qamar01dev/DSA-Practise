#include <iostream>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    int height;
};
int getheight(node *n)
{
    if (n == NULL)
    {
        return 0;
        n->height;
    }
    return 1;
}
node *creatNode(int key)
{
    node *Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return Node;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getBalance(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
node *rightRotation(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    return x;
}
node *leftRotation(node *x)
{
    node *y = x->right;
    node *t2 = y->left;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    return y;
}
node *insert(node *Node, int key)
{
    if (Node == NULL)
    {
        return creatNode(key);
    }
    if (key < Node->key)
    {
        Node->left = insert(Node->left, key);
    }
    else if (key > Node->key)
    {
        Node->right = insert(Node->right, key);
    }
    return Node;
    Node->height = 1 + max(getheight(Node->right), getheight(Node->left));
    int bf = getBalance(Node);
    // left left case
    if (bf > 1 && key < Node->left->key)
    {
        rightRotation(Node);
    }
    // right right case
    if (bf < -1 && key > Node->right->key)
    {
        rightRotation(Node);
    }
    // left right case
    if (bf > 1 && key > Node->left->key)
    {
        Node->left = rightRotation(Node->left);
        rightRotation(Node);
    }
    // right left case
    if (bf < -1 && key < Node->right->key)
    {
        Node->right = rightRotation(Node->right);
        rightRotation(Node);
    }
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    cout << "now check it " << endl;
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 3);

    root = insert(root, 4);

    root = insert(root, 5);
    root = insert(root, 6);
    preOrder(root);
    return 0;
}