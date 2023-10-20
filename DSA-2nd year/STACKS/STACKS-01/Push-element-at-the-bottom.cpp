#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s1;
    int n;
    cin >> n;
    while (s1.size() <n)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    stack<int> t1;
    while (s1.size() > 0)
    {
        t1.push(s1.top());
        s1.pop();
    }
int btx;
cin>>btx;
s1.push(btx);
while (t1.size()>0)
{
    s1.push(t1.top());
    t1.pop();
}
while (s1.size()>0)
{
    cout<<s1.top()<<" ";
    s1.pop();
}

    return 0;
}