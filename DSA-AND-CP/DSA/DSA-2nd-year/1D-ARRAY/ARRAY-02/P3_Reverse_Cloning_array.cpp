#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<" Enter the number of elements-"<<endl;
    cin>>n;
    vector<int>v;
    cout<<" Enter the of elements-"<<endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>Vr;
    for (int i = 0; i < n; i++)
    {
        Vr.push_back(v[n-i-1]);
    }
    cout<<'[';
for (int i = 0; i < n; i++)
{
    cout<<Vr[i]<<" ";
}
cout<<']';
    return 0;
}