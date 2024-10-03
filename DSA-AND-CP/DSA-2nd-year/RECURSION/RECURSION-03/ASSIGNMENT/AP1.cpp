#include <bits/stdc++.h>
using namespace std;
//print array elements in the reverse order
void revrec(vector<int>&v,int idx){
    int n=v.size();
    if (idx==n)
    {
        return;
    }
    revrec(v,idx+1);
    cout<<v[idx]<<" ";
}
int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    revrec(v,0);
    return 0;
}