#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
node * creatnode(int data)
{
    node *n = new node;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}
void inOrder(node * root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int isBST(node *root){
    static node *prev = NULL;
    if(root!=NULL){
        if (!isBST(root->left))
        {
            return 0;
        } 
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
node* InsertInbinary(node * root , int key){
     node * prev = NULL;
     node * curr = root;
    while (curr!=NULL)
    {
        prev = curr;
    if(key == curr->data){
        return root;
    }
    else if(key < curr ->data){
        curr = curr->left;
    }
    else{
        curr = curr->right;
    }
}
 node *new_node = creatnode(key);
 if(prev == NULL){
        return new_node;
    }
if(key< prev->data){
    prev->left = new_node;
}else{
    prev->right = new_node;
}
return root;
}

int main()
{
    node *p = creatnode(5);
    node *p1 = creatnode(3);
    node *p2 = creatnode(6);
    
    p->left = p1;
    p->right = p2;

    cout <<"right node is "<<p->right->data<<endl;
    cout <<"root is "<<p->data<<endl;
    cout <<"left node is "<<p->left->data<<endl;
    cout <<"now output "<<endl;
    InsertInbinary(p, 7);

    cout << "p->right->left data: " << p->right->right->data << endl;

    cout << "InOrder Traversal: ";
    inOrder(p);
    cout << endl;
}