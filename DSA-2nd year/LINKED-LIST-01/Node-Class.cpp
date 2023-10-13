#include <bits/stdc++.h>
using namespace std;
//class node
class Node{
    public:
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=NULL;
    }
};
int main() {
 Node a(10);
 Node b(20);
 Node c(30);
 Node d(40);
cout<<a.next<<endl;
a.next=&b;
b.next=&c;
c.next=&d;
cout<<a.next->next->next->val<<endl;
Node temp=a;
while (1)
{
    cout<<temp.val<<" ";
    if(temp.next==NULL) break;
    temp=*(temp.next);
}

    return 0;
}