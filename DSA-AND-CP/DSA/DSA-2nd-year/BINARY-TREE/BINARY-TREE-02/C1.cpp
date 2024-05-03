#include <bits/stdc++.h>
using namespace std;
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
//preorder-postorder-inorder approaches☑️

//level order traversal using dfs algorithm
void helper(Node* root,int j,int k){
     if(root==nullptr) return ;
     if(j==k) cout<<root->val<<" ";
     helper(root->left,j+1,k);
     helper(root->right,j+1,k);
}
//try printing elements of nth levels
void PrintNthLevels(Node* root,int k){
    int j=1;
    helper(root,j,k);
}

//print  elements in the format of levels
int levels(Node* root){
    if(root==nullptr) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
void LOT(Node* root){
   for (int i = 1; i <=levels(root); i++)
   {
        PrintNthLevels(root,i);
        cout<<endl;
   }
}

int main() {
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    PrintNthLevels(a,3);
    cout<<endl;
    LOT(a);
    return 0;
}