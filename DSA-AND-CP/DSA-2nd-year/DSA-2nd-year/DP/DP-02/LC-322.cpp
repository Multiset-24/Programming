//https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

vector<int>dp;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1000006, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main() {
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);

    for(int i=0;i<n;i++) cin>>coins[i];
    
    Solution coin;

    cout<<coin.coinChange(coins,x);
    return 0;
}