#include <iostream>
using namespace std;
#include "C2.cpp"
// push at bottom
void pushAtBottom(stack<int> &st, int val)
{
    if (st.size() == 0)
        st.push(val);
    int x = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(x);
}
// push element at any index-iterative way
void push_idx(stack<int> &st, int idx, int val)
{
    stack<int> temp;
    while (st.size() > idx)
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while (temp.size() > 0)
    {
        st.push(temp.top());
        temp.pop();
    }
}
// Print the elements of stack using recursion
void print_rec(stack<int> &st)
{
    if (st.size() == 0)
        return;
    cout << st.top() << ' ';
    int x = st.top();
    st.pop();
    print_rec(st);
    st.push(x);
}
// we can also print the stack in it's original order using recursion just by changing the cout line's position
void print_rec_rev(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int x = st.top();
    st.pop();
    print_rec_rev(st);
    st.push(x);
    cout << st.top() << ' ';
}
// reversing the array using recursion
void rev_rec(stack<int> &st)
{
    if (st.size() == 1)
        return;
    int x = st.top();
    st.pop();
    rev_rec(st);
    pushAtBottom(st, x);
}
