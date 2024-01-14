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
// use of bfs to construct and display the binary tree level wise
Node *construct_queue(int arr[], int n)
{
    queue<Node *> q;
    int i = 1;
    int j = 2;
    Node *root = new Node(arr[0]);
    q.push(root);
    while (q.size() > 0 && i < n)
    {
        Node *temp = q.front();
        q.pop();
        Node *l;
        Node *r;
        if (arr[i] != INT_MIN)
            l = new Node(arr[i]);
        else
            l = nullptr;
        if (j != n && arr[j] != INT_MIN)
            r = new Node(arr[j]);
        else
            r = nullptr;
        if (l != nullptr)
            q.push(l);
        if (r != nullptr)
            q.push(r);
        temp->left = l;
        temp->right = r;
        i += 2;
        j += 2;
    }
    return root;
}
void BfsTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

// BOUNDARY TRAVERSAL---------->
void LeftBoundary(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    cout << root->val << " ";
    LeftBoundary(root->left);
    if (root->left == nullptr)
        LeftBoundary(root->right);
}
void BottomBoundary(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        cout << root->val << " ";
    ;
    BottomBoundary(root->left);
    BottomBoundary(root->right);
}
void RighBoundary(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    RighBoundary(root->right);
    if (root->right == nullptr)
        RighBoundary(root->left);
    cout << root->val << " ";
}
void boundary(Node *root)
{
    LeftBoundary(root);
    BottomBoundary(root);
    RighBoundary(root);
    return ;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN,8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28};
    Node *root = construct_queue(arr, 45);
    BfsTraversal(root);
    cout << endl;
    // Boundary traversal
    boundary(root);
    return 0;
}