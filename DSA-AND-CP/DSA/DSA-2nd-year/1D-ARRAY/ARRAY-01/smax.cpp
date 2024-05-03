#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,target;
    cout<<"Enter the size of array-";
    cin>>n;
    int arr[n];
cout<<"Enter the elements of the array-";
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int max=arr[0];
for (int i = 1; i <n; i++)
{
    if(arr[i]>max){
        max=arr[i];
    }
}
cout<<"The maximum element is-"<<max;
int smax=arr[0];
for(int j= 0; j<n; j++)
{
    if(arr[j]>smax && arr[j]!=max){
        smax=arr[j];
    }
}
cout<<"The second maximum element is-"<<smax;
    return 0;
}