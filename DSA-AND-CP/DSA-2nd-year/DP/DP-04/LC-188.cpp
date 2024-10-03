#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#define mod 1000000007
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)


class Solution {
public:
    int dp[10005][105][2];
    int f(vector<int>& prices,int idx,int k,bool ON){
        if(idx==prices.size()) return 0;

        if(dp[idx][k][ON]!=-1) return dp[idx][k][ON];
        //no buying of stocks
        int ans=f(prices,idx+1,k,ON);
        //buying and selling of stocks
        if(ON==true){
            if(k>0)ans=max(ans,f(prices,idx+1,k-1,false)-prices[idx]);
        }else{
            ans=max(ans,f(prices,idx+1,k,true)+prices[idx]);
        }
        return dp[idx][k][ON]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        bool ON=true;
        int idx=0;
        memset(dp, -1, sizeof(dp));
        return f(prices,idx,k,ON);
    }
};
int main() {
 
    return 0;
}