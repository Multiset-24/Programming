#include <bits/stdc++.h>
using namespace std;
//find the duplicate number in the array leetcode-287
int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        //[3,1,3,4,2]
        while(i<n){
            if(nums[nums[i]]==nums[i]) return nums[i];
            else swap(nums[i],nums[nums[i]]);

        };
        return 1000;
    }
int main() {
 
    return 0;
}