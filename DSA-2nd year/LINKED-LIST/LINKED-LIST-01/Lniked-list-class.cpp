#include <bits/stdc++.h>
using namespace std;
class Node
{ // user defined data type
public:
    int val;
    Node *Next;
    Node(int val)
    {
        this->val = val;
        this->Next = NULL;
    }
};
class linked_list
{
public:
    Node *head;
    Node *tail;
    int size;
    linked_list()
    {
        head = tail = NULL;
        size = 0;
    }
    void insetAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->Next = temp;
            tail = temp;
        }
        size++;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
};
void insert_at_end(Node *head, int v)
{
    Node* list=new Node(v);
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next= list;
}
int main()
{
    linked_list ll; //{ }
    ll.insetAtEnd(10);
    ll.display();
    ll.insetAtEnd(20);
    ll.display();
    ll.insetAtEnd(30);
    ll.display();
    ll.insetAtEnd(40);
    ll.display();
    cout << ll.size << endl;
    insert_at_end(ll.head, 60);
    ll.display();
    return 0;
}