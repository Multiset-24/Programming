#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int i=0,j=n-1;
    while(i<=j){    //yha galti kari thi used i<j
         int temp=v[i];
         v[i]=v[j];
         v[j]=temp;
         i++;
         j--;
    }
    for (int k = 0; k < n; k++)
    {
       cout<<v[k]<<" ";
    }
    return 0;
}