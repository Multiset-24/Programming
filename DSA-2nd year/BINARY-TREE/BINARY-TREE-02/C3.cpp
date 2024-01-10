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

void levelOrderqueue(Node* root){//bfs
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=nullptr) q.push(temp->left);
        if(temp->right!=nullptr) q.push(temp->right);
    }
    cout<<endl;
}

// construct tree from level order traversal
//{1,2,3,4,5,6,N,N,7,8,9,N};

Node* construct(int arr[],int n){
    queue<Node*>q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(!q.empty() && i<n){
        Node* temp=q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=nullptr;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);//important condition why there is condition on n just beware of it
        else r=nullptr;
        temp->left=l;
        temp->right=r;
        if(l!=nullptr) q.push(l);
        if(r!=nullptr) q.push(r);
        i+=2;
        j+=2;
    }
        return root;
}
int main() {
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=construct(arr,n);
    levelOrderqueue(root);
    return 0;
}