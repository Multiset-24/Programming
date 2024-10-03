#include <bits/stdc++.h>
using namespace std;
// intro to the linked list and it's class(most basic one)
class node{
public:
int val;
node* next;
node(int v){
    val=v;
    next=NULL;
}
};
int main() {
    node a(10);
    node b(20);
    a.next=&b;
    node c(30);
    b.next=&c;
    node d(40);
    c.next=&d;
    cout<<((a.next))->next->val;
    return 0;
}