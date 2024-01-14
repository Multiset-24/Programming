#include <bits/stdc++.h>
using namespace std;
//print array using recursion 
/*-------MY TRY---------*/
void tarec(int arr[],int n){
          if(n<0){
            return;
          }
          tarec(arr,n-1);
          cout<<arr[n]<<" ";
}
/*-------CORRECT APPROACH-----*/
void display(int arr[],int n,int idx){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
    display(arr,n,idx+1);
}
//TBH we don't need idx in the above function
int main() {
    int arr[]={1,2,3,4,5,6,7};
    tarec(arr,6);
    cout<<endl;
    display(arr,7,0);
    return 0;
}