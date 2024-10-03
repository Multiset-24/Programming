#include <bits/stdc++.h>
using namespace std;


class helper{
    public:
    bool operator()(int a ,int b){
        return a>b;
    }
};
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,helper>pq(nums.begin(),nums.end());
        int sum=0;
        while(k--){
                int num=pq.top();
                if(num==0) break;
                pq.pop();
                pq.push(-num);
        }

        while(pq.size()>0){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
int main() {
 
    return 0;
}