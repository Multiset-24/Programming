#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
#define mod 1000000007
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,INT_MAX);

        dp[0]=0;

        for(int i=0;i<=n;i++){
            int start=max(i-ranges[i],0);
            int end=min(n,i+ranges[i]);
            int ans=INT_MAX;

            for(int j=start;j<=end;j++){
                ans=min(ans,dp[j]);
            }

            if(ans!=INT_MAX){
                dp[end]=min(dp[end],ans+1);
            }
            if(dp[n]==1) break;
        }

        return dp[n]==INT_MAX?-1:dp[n];
    }
};
int main() {
 
    return 0;
}