#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

class Solution {
public:
    // vector
    vector<int>f(vector<int>&dp,int n){
            dp[0]=0;
            int offset=1;
        for(int i=1;i<=n;i++){
                if(i==offset*2){
                    offset*=2;
                }

                dp[i]=1+dp[i-offset];
            }
        
        return dp;
    }
    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        dp=f(dp,n);
        return dp;
    }
};


int main() {
 
    return 0;
}