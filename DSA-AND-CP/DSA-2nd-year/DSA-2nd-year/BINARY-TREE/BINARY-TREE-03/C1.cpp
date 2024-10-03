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
// dfs traversals using iterative approach

// preorder traversal
//ek stack banao st aur usme root ko daal do phir ek while loop lagao usme ek temp node banao jisme stack ka top store use phir stack se uska top pop out kardo aur phir usme temp ka right pehle daalo phir temp ka left daaldo and then print out the temp->val this would give the preorder of tree....
void preorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.size() > 0)
    {
        Node *temp = st.top();
        st.pop();
        if (temp->right != nullptr)
            st.push(temp->right);
        if (temp->left != nullptr)
            st.push(temp->left);
        cout << temp->val << " ";
    }
}

// postorder traversal
//bs ek stack banao aur operations saare vhi last vale perform karne hai except iss baar pehle right vale ko stack mai pehle push karna hai taaki hamare pass postorder ka ulta sequence aajaye baad mai isko ek vector mai store karake reverse mai print kardenge taaki hamare pass postorder sequence of tree aajayga...
void postorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    vector<Node *> helper;
    while (st.size() > 0)
    {
        Node *temp = st.top();
        st.pop();
        if (temp->left != nullptr)
            st.push(temp->left);
        if (temp->right != nullptr)
            st.push(temp->right);
        helper.push_back(temp);
    }
    for (int i = helper.size() - 1; i >= 0; i--)
    {
        cout << (helper[i])->val << " ";
    }
}

// inorder traversal
//isme hum pehle ek node ke andar root ko store karenge than ek helper stack ka use lenge ek while loop banao usme agar node ki val nullptr  nhi hai to stack ke andar node ko push kardo and node ko node ke left se reinitialise kardo agr node ki value nullptr hai to ek temp node ke andar helper ke top ko store karo and then use pop kardo and print temp ki value and iske baad node ko temp ke right se reinitialise kardo taaki hum right tk node ko pahucha de...
void inorder(Node *root)
{
    Node *node = root;
    stack<Node *> helper;
    while (helper.size() != 0 || node != nullptr)
    {
        if (node != nullptr)
        {
            helper.push(node);
            node = node->left;
        }
        else{
            Node* temp=helper.top();
            helper.pop();
            cout<<temp->val<<" ";
            node=temp->right;
        }
    }
}


int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    preorder(a);
    cout << endl;
    postorder(a);
    cout<<endl;
    inorder(a);
    return 0;
}