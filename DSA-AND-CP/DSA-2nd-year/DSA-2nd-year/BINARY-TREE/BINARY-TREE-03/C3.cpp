#include <bits/stdc++.h>
using namespace std;

// Structure for a tree node
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
// Function to print the top view of the binary tree
void topView(Node *root)
{
    unordered_map<int, int> m;
    queue<pair<Node *, int>> q;
    pair<Node *, int> p; // Node* is for elements of tree and int is for the levels of the node i.e horizontal distance..
    p.first = root;
    p.second = 0;
    q.push(p);
    m[0] = root->val; // map==<levels,root's value>
    while (q.size()>0)
    {
        Node *temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if (m.find(level) == m.end())
            m[level] = temp->val;
        if (temp->left != nullptr)
        {
            pair<Node *, int> p;
            p.first = temp->left;
            p.second = level-1;
            q.push(p);
        }
        if (temp->right != nullptr)
        {
            pair<Node *, int> p;
            p.first = temp->right;
            p.second = level+1;
            q.push(p);
        }
    }
    int minLevel=INT_MAX;
    int maxLevel=INT_MIN;
    for(auto ele:m){
        int level=ele.first;
        minLevel=min(minLevel,level);
        maxLevel=max(maxLevel,level);
    }
    for(int i=minLevel;i<=maxLevel;i++){
        cout<<m[i]<<" ";
    }
}
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    root->left->right->right->right->right = new Node(7);

    cout << "Top view of the binary tree is: ";
    topView(root);

    return 0;
}

//for the bottom view just remove the condition i.e if level is not present then input , for bottom view it should update everytime it found  a element with that horizontal distnce since we are doing bfs level order traversal 😏😁
