#include <bits/stdc++.h>
using namespace std;
// implementation of binary tree using pointers
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// this is just an example there can be three ways to print this
void display(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->val<<" ";
    display(root->left);
    display(root->right);
}

//find the sum of binary
int sum(Node* root){
    if(root==nullptr) return 0;
    return root->val+sum(root->left)+sum(root->right);
}

//find size of binary tree
int size(Node* root){
    if(root==nullptr) return 0;
    return 1+size(root->left)+size(root->right);
}

//find the maximum value of the element in the binary tree
int MAX(Node* root){
    if(root==nullptr) return INT_MIN;
    return max(root->val,max(MAX(root->left),MAX(root->right)));
}

//find the no of levels in binary tree
int levels(Node* root){
    if(root==nullptr) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
int main()
{
    Node *a = new Node(5);
    Node *b = new Node(4);
    Node *c = new Node(-3);
    Node *d = new Node(2);
    Node *e = new Node(69);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    display(a);
    cout<<endl<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<MAX(a)<<endl<<levels(a);
    return 0;
}