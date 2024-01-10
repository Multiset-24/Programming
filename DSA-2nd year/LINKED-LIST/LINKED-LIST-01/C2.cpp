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
     int j=0;
    while(head!=nullptr){
        head=head->next;
        j++;
    }
    return j;
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
    if (ll_size(head) == 0 || ll_size(head) == 1)
        return nullptr;
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// how to delete the element from the tail
node *delete_tail(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// how to delete the element from any index
node *_delete(node *head, int k)
{
    int j = 0;
    node *temp = head;
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    if (k == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    if (k == ll_size(head) - 1)
    {
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    while (j < k)
    {
        if (j == k - 1)
        {
            temp->next = temp->next->next;
            return head;
        }
        j++;
        temp = temp->next;
    }
}

// how to insert any element at any index
node *_insert(node *head, int k, int val)
{
    node *newnode = new node(val);
    node *temp = head;
    if (head == nullptr)
    {
        head = newnode;
        return head;
    }
    if (k == 0)
    {
       newnode->next=head;
       head=newnode;
        return head;
    }
    if (k>=ll_size(head) )
    {
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
    int j = 0;
    while (j < k - 1)
    {
        temp = temp->next;
        j++;
    }
    node *temp2 = temp->next;
    temp->next = newnode;
    newnode->next = temp2;
    return head;
}

node* removeElements(node* head, int val) {
        node* temp=head;
        if(head->val==val){
            head=head->next;
        }
        if(temp->next==nullptr||temp->val==val){
            temp=nullptr;
        }
        while(temp->next!=nullptr){
            node* temp1=temp;
            if(temp->next->val==val){
                node* temp2=temp1->next;
                temp1->next=temp1->next->next;
                delete temp2;
            }
            temp=temp->next;  
        }
        return head;
    }
    
 node* mergeTwoLists(node* list1, node* list2) {
        //O(1) space complexity
        node* c=new node(-1);
        node* a=list1;
        node* b=list2;
        node* temp=c;
        while(a!= nullptr && b!= nullptr){
            if(a->val>b->val){
                temp->next=b;
                temp=b;
                b=b->next;
            }
            else{
                temp->next=a;
                temp=a;
                a=a->next;
            }
        }
        if(a==nullptr){
            temp->next=b;
        }
        else{
            temp->next=a;
        }
        return c->next;
    }
    node* mid(node* head){
        node* slow=head;
        node* fast=head->next;
        while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        }
        node* mid=slow->next;
        slow->next=nullptr;
        return mid;
    }
    node* sortList(node* head) {
        if(head==nullptr || head->next==nullptr) return head;
        node* middle=mid(head);
        node* a=sortList(middle);
        node* b=sortList(head);
        node* c=mergeTwoLists(a,b);
        return c;
    }
int main()
{
    vector<int> v = {10,56,6,10,11,6,5,6};
    node *head = vector_to_ll(v);
    display_ll(head);
    // cout << ll_size(head) << endl;
    // cout << head->val << endl;
    // head = delete_head(head);
    // cout << head->val << endl;
    // head = delete_tail(head);
    // display_ll(head);
    // head = _delete(head, 6);
    // head=_insert(head,2,54);
    // display_ll(head);
    // head=removeElements(head,6);
    // display_ll(head);
    cout<<ll_size(head);
    head=sortList(head);
    cout<<endl;
    display_ll(head);
    return 0;
}