#include <bits/stdc++.h>
using namespace std;
void reverse(int i,int j,vector<int>&v){
    while (i<=j)
    {
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
    return;
}
int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for ( int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int k;//number of times a array(vector)needs to be rotated k!=>n
    cin>>k;
    if(k>n) k=k%n;
    reverse(0,n-k-1,v);
    reverse(n-k,n-1,v);
    reverse(0,n-1,v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}