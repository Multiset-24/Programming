#include <bits/stdc++.h>
using namespace std;
// given an integer array where every elements occurs twice except two numbers find those numbers using bit manipulation ?

vector<int>find_2_unique(vector<int>&nums){
    int xor_result=nums[0];
    //first calculate xor of two numbers which are unique
    for (int i = 1; i < nums.size(); i++)
    {
        xor_result^=nums[i];
    }
    int set_bit=1;
    //then calculate the number with the first set bit in the xor result
    while ((set_bit & xor_result)==0)
    {
        set_bit<<=1;
    }
    //now traverse through the loop to calculate two unique number using first set bit number and xor operator's property
    vector<int>ans(2,0);
    for (int i = 0; i < nums.size(); i++)
    {
        if((set_bit & nums[i])==0){
               ans[0]^=nums[i];
        }
        else{
            ans[1]^=nums[i];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int>ans=find_2_unique(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}