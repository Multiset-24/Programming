#include <bits/stdc++.h>
using namespace std;
//leetcode-169----->majority element

//Method-01------>leetcode time limit exceeded
int majorityElement01(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
           int count =1;
           for(int j=i+1;j<n;j++){
               if(nums[i]==nums[j]) count++;
           }
           if(count>n/2) return nums[i];
       }
        return -1;
    }

//Method01-------->Badass way
 int majorityElement02(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       return nums[n/2];
    }    
int main() {
    vector<int>v(5);
    cout<<" Enter the elements of the array-";
    for (int i = 0; i < 5; i++)
    {
        cin>>v[i];
    }
    cout<<majorityElement01(v)<<endl;
    cout<<majorityElement02(v)<<endl;
    return 0;
}