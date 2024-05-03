#include <bits/stdc++.h>
using namespace std;
//find maximum of the array using recursion 
void print_max(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    } if(max<arr[idx]) max=arr[idx];
    print_max(arr,n,idx+1,max);
}
// storing function
int _max(int arr[],int n,int idx){
    if (idx==n)
    {
         return INT_MIN;
    }
    return max(arr[idx],_max(arr,n,idx+1));
}
int main() {
    int arr[]={2,4,2,4,5,600,4,53,564};
    print_max(arr,9,0,INT_MIN);
    cout<<endl<<_max(arr,9,0);
     return 0;
}