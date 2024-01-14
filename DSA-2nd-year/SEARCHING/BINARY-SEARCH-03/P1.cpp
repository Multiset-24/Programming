#include <bits/stdc++.h>
using namespace std;
//leetcode 1011 capacity to ship packages with d days
    bool check(int mid,vector<int>&weights,int days){
        int n=weights.size();
        int m=mid;
        int count=1;
        for(int i=0;i<n;i++){
            if(m>=weights[i]){
                m-=weights[i];
            }
            else{
                count++;
                m=mid;
                m-=weights[i];
            }
        }
        if(count>days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int max=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(max<weights[i]) max=weights[i];
            sum+=weights[i];
        }
        int lo=max;
        int hi=sum;
        int minCapacity=sum;
        while(lo<=hi){
           int  mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                minCapacity=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return minCapacity;
    }
int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int days;
    cin>>days;
    shipWithinDays(v,days);
    return 0;
}