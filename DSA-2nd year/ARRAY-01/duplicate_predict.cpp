#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    bool flag=true;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < (n-1); i++)
    {
        for (int j = i+1; j<n; j++)
        {
            if(arr[i]==arr[j]){
                flag=true;
                cout<<"duplicate is present";
                break;
            }
            else{
                flag=false;
            }
        }
        if(flag) break;
    }
    if(!flag) cout<<"duplicate not present";
    return 0;
}