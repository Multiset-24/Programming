#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>target){
            count++;
        }
    }
    cout<<count;
    return 0;
}