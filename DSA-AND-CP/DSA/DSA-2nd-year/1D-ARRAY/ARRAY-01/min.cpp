#include <bits/stdc++.h>
using namespace std;
// find the minimum element in the array
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int min=INT_MAX;
    for (int i = 0; i < n; i++)
    {
    if(min>arr[i])
    {
      min=arr[i]; 
    }  
    }
    cout<<min;
    return 0;
}