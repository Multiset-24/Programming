#include <bits/stdc++.h>
using namespace std;
//find the maximum sum of subarray of size k using both approaches which includes sliding window and normal approach

//the time complexity of this program is O(n^2)
void normal_approach(vector<int>&nums,int k){
    int n=nums.size();
    int max_sum=INT_MIN;
    int max_idx=0;
    for (int i = 0; i <=n-k; i++)
    {
        int sum=0;
        for (int j = i; j<=i+k; j++)
        {
            sum+=nums[i];
        }
        if(max_sum<sum){
            max_sum=sum;
            max_idx=i;
        }
    }
    cout<<"The maximum idx is "<<max_idx<<" and maximum sum is "<<max_sum<<endl;
}

//the time complexity of this program is O(n)=O((n-k)+k)
void sliding_window_approach(vector<int>&nums,int k){
    int n=nums.size();
    int i=1;
    int j=k;
    int sum=0;
    int max_idx;
    for (int i = 0; i < k; i++)
    {
        sum+=nums[i];
    }
    int max_sum=sum;
    while(j<n){
        sum+=nums[j]-nums[i-1];
        if(max_sum<sum){
            max_sum=sum;
            max_idx=i;
        }
        i++;
        j++;
    }
    cout<<"The maximum idx is "<<max_idx<<" and maximum sum is "<<max_sum<<endl;
}
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    normal_approach(nums,3);
    sliding_window_approach(nums,3);
    return 0;
}