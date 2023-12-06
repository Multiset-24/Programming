#include <bits/stdc++.h>
using namespace std;
// main implementation of the linked list
class node
{
public:
    int val;
    node *next;
    node(int val, node *next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};
// conversion of vector to linked list
node *vector_to_ll(vector<int> &v)
{
    node *head = nullptr;
    node *tail = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        node *newnode = new node(v[i]);
        if (head == nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}
// display of linked list
void display_ll(node *head)
{
    node *temp;
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

// how to get the size of the linked list
int ll_size(node *head)
{
    node *temp;
    temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// how to linear search any element in the linked list
int ll_search(node *head, int target)
{
    node *temp;
    temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (temp->val == target)
            return count;
        temp = temp->next;
    }
    return 0;
}

// how to delete the head of the linked list
node *delete_head(node *head)
{
    if(ll_size(head)==0 || ll_size(head)==1) return nullptr;
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
node* delete_tail(node* head){
    if(head==nullptr||head->next==nullptr) return nullptr;
    node* temp=head;
    while (temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
int main()
{
    vector<int> v={10,1,2,5,3,2};
    node *head = vector_to_ll(v);
    display_ll(head);
    cout << ll_size(head)<<endl;
    cout<<head->val<<endl;
    head = delete_head(head);
    cout<<head->val<<endl;
    head=delete_tail(head);
    display_ll(head);
    return 0;
}