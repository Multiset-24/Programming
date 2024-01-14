#include <bits/stdc++.h>
using namespace std;
void linear_search(int n,int arr[],int target){
    bool found=true;
       for (int  i = 0; i < n; i++)
       {
        if(target==arr[i]){
            cout<<"The index of the element is-"<<i;
            break;
        }
        else{
            found=false;
        }
       }
       if(found==false){
        cout<<"element not found";
       }
}
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
cout<<"Enter the target elemment";
cin>>target;
linear_search(n,arr,target);

    return 0;
}