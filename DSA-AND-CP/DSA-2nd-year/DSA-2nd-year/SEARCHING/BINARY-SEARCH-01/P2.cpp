#include <bits/stdc++.h>
using namespace std;
//the first occurence of 'x' in the array.if 'x' does not exist return -1
// go for leetcode 34
void first_occurence(vector<int>&v,int target){
    sort(v.begin(),v.end());
    int n=v.size();
    int lo=0;
    int hi=n-1;
    int mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if (v[mid]==target)
        {
            if (v[mid-1]==target)
            {
                hi=mid-1;
            }
            else{
                cout<<"This is index for the first occurence"<<mid;
                break;
            }
            
        }
        else if(v[mid]<target) lo=mid+1;
        else if(v[mid]>target) hi=mid-1;
    }
}
//leetcode 34
int main() {
 int n;
 cin>>n;
 vector<int>v(n);
 for (int i = 0; i < n; i++)
 {
    cin>>v[i];
 }
 int target;
 cin>>target;
 first_occurence(v,target);
    return 0;
}