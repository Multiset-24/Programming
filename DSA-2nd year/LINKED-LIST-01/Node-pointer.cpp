#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};
void display(Node *head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void display_size(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    cout <<"The size of the linked list is -"<< size;
    cout<<endl;
}
void display_recursion(Node *head)
{
    if (head == NULL)
        return;
    cout << head->val << " ";
    display_recursion(head->next);
}
void display_recursion_reverse(Node *head)
{
    cout<<endl;
    if (head == NULL)
        return;
    display_recursion_reverse(head->next);
    cout << head->val << " ";
}
int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    cout << a->next->val << endl; // easy hogya pointer ki help se
    display(a);
    display_size(a);
    display_recursion(a);
    display_recursion_reverse(a);
    return 0;
}