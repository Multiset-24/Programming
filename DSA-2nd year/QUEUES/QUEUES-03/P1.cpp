#include <bits/stdc++.h>
using namespace std;
//reorder queue(by using one stack only)

queue<int> Reorder_Queue(queue<int>&q){
    int n=q.size();
    stack<int>helper;
    while(helper.size()<=n/2){
        helper.push(q.front());
        q.pop();
    }
    while(helper.size()!=0){
        q.push(helper.top());
        helper.pop();
    }
    while(helper.size()<=n/2){
        helper.push(q.front());
        q.pop();
    }
    while(helper.size()!=0){
        q.push(helper.top());
        helper.pop();
        int x=q.front();
        q.pop();
        q.push(x);
    }
    while(q.size()!=0){
        helper.push(q.front());
        q.pop();
    }
    while(helper.size()!=0){
        q.push(helper.top());
        helper.pop();
    }
    return q;
}
int main() {
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q=Reorder_Queue(q);
    int n=q.size();
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        int x=q.front();
        q.pop();
        q.push(x);
    }
    return 0;
}