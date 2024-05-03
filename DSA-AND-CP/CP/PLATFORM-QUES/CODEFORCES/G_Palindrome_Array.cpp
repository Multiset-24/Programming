#include<bits/stdc++.h>
using namespace std;
 
 
isPalindrome(vector<int>&arr,int i,int j){
    if(i>j)return true;
    return (arr[i]==arr[j])?isPalindrome(arr,i+1,j-1):false;
}
int main(){
    int n;
    cin>>n;
    int i=0;
    int j=n-1;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    if(isPalindrome(arr,i,j)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
    
}
