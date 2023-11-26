#include <bits/stdc++.h>
using namespace std;
// leetcode 1052
//grumpy store owner problem 
class Solution {
public:
/*
customers=
[1,0,1,2,1,1,7,5]
grumpy =
[0,1,0,1,0,1,0,1]
minutes=3
customers =[4,10,10]
grumpy =[1,1,0]
minutes =2
*/
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int n=grumpy.size();
       int i=1;
       int j=minutes;
       int loss=0;
       for(int i=0;i<minutes;i++){
           if(grumpy[i]==1) loss+=customers[i];
       }
        int max_loss=loss;
        int max_idx=0;
       while(j<n){//important step
           if(grumpy[j]==1) loss+=customers[j];
           if(grumpy[i-1]==1) loss-=customers[i-1];
            if(max_loss<loss){
                max_loss=loss;
                max_idx=i;
            }
            i++;
            j++;
       }
    for(int i=max_idx;i<(max_idx+minutes);i++){
         grumpy[i]=0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==0) ans+=customers[i];
    }
    return ans;
    }
};
int main() {
 
    return 0;
}