#include <iostream>
// if not used bits libraray always include #inlcude<stacks>----------
using namespace std;
#include <vector>
#include "P1.cpp"
//print a stack using an extra stack
void print_stack(stack<int> st)
{
    stack<int> temp;
    while (st.size() > 0)
    {
        cout << st.top() << " ";
        int x = st.top();
        st.pop();
        temp.push(x);
    }
    // puttings leements from back to original stack
    while (temp.size() > 0)
    {
        int x = temp.top();
        st.push(x);
        temp.pop();
    }
    cout<<endl;
}
//print a reversed stack using an extra stack
void print_rev(stack<int> st)
{
    stack<int> temp;
    while (st.size() > 0)
    {
        temp.push(st.top());
        st.pop();
    }
    while (temp.size() > 0)
    {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
}
//reverse the stack without using an extra stacks and also print it
void print_rev2(stack<int>&st){
    vector<int> v;
    while (st.size() > 0)
    {
        v.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < v.size(); i++)
    {
        st.push(v[i]);
    }
    cout << endl;
    print_stack(st);
}
int main()
{
    stack<int> st;
    //pushing onto the stack
    {
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    }
    cout<<st.top();
    cout<<endl;
    print_stack(st);
    print_rev(st);
    print_rev2(st);
    push_idx(st,5,0);
    print_stack(st);
    print_rec(st);
    cout<<endl;
    print_rec_rev(st);
    rev_rec(st);
    print_stack(st);
    return 0;
}