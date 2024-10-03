#include <bits/stdc++.h>
using namespace std;
//find all numbers disappeared in an array
vector<int> findDisappearedNumbers(vector<int>& nums) {
           int n=nums.size();
           int i=0;
           while(i<n){
               if(nums[nums[i]-1]==nums[i]) i++;
               else swap(nums[nums[i]-1],nums[i]);
           }
           vector<int>ans;
           for(int i=0;i<n;i++){
               if(nums[i]!=i+1) ans.push_back(i+1);
           }
           return ans;
    }
int main() {
 
    return 0;
}