#include <bits/stdc++.h>
using namespace std;
// Print index of a given element in an array. If not present, print -1.
void printindex(vector<int> &v, int e, int idx,bool flag)
{
    int n = v.size();
    if (v[idx] == e)
    {
        cout<<idx<<" ";
        flag =true;
    }
    if(idx==n && flag==false) {
        cout<<-1;
        return;
    }
    else if(idx==n) return;
    printindex(v, e, idx + 1,flag);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int e; // element to be searched in the vector
    cin >> e;
    printindex(v, e, 0,false);
    return 0;
}