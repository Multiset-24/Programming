// star triangle pyramid
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cout<<"enter the number";
    cin>>n;
for (int i = 0; i <n; i++)
{
    for (int j=0;j<(n-i-1);j++)
    {
        cout<<" ";
    }
    for (int j=0;j<(2*i+1);j++)
    {
        cout<<"*";
    }
    for (int j=0;j<(n-i-1);j++)
    {
        cout<<" ";
    }
    cout<<endl;
    }
    
    
return 0;
}

