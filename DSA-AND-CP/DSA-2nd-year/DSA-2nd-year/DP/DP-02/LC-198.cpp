#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/

class Solution {
public:
    // int helper(vector<int>&nums,int idx,vector<int>&dp){
    //     // if(idx>=nums.size()) return INT_MIN;
    //     if(idx==nums.size()-1) return nums[idx];
    //     if(idx==nums.size()-2) return max(nums[idx],nums[idx+1]);
    //     if(dp[idx]!=-1) return dp[idx];
    //     else return dp[idx]=max(0+helper(nums,idx+1,dp),helper(nums,idx+2,dp)+nums[idx]);
    // }
    vector<int>dp;
    int helperTD(vector<int>&nums,int idx){
        if(idx==nums.size()-1) return nums[idx];
        if(idx==nums.size()-2) return max(nums[idx],nums[idx+1]);
        if(dp[idx]!=-1) return dp[idx];
        else return dp[idx]=max(0+helperTD(nums,idx+1),helperTD(nums,idx+2)+nums[idx]);
    }
    int rob(vector<int>& nums) {
        int idx=0;
        dp.clear();
        dp.resize(105,-1);
        return helperTD(nums,idx);
    }
};

int main() {
 
    return 0;
}