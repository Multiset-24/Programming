#include <bits/stdc++.h>
using namespace std;

// kanpsack-0/1 problem

// https://atcoder.jp/contests/dp/tasks/dp_d
#define mod 1000000007
#define ll long long int

vector<vector<ll>> dp;

ll f(ll W, ll idx, vector<ll> value, vector<ll> weight)
{
    if (idx >= value.size())
        return 0;

    ll ans = INT_MIN;
    if (dp[W][idx] != -1)
        return dp[idx][W];
    ans = max(f(W, idx + 1, value, weight), ans);

    if (W >= weight[idx])
    {
        ans = max(value[idx] + f(W - weight[idx], idx + 1, value, weight), ans);
    }

    return dp[W][idx] = ans;
}

ll fbu(ll W, vector<ll> value, vector<ll> weight)
{
    dp.resize(105, vector<ll>(100005, 0));

    int n = weight.size();

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int j = 0; j <= W; j++)
        {
            ll ans = INT_MIN;
            
            ans=max(ans,dp[idx+1][j]);

            if(weight[idx]<=j){
                ans=max(ans,value[idx]+dp[idx+1][j-weight[idx]]);
            }
            dp[idx][j]=ans;
        }
    }
    return dp[0][W];
}
int main()
{
    dp.clear();

    ll N, W;
    cin >> N >> W;

    vector<ll> weight(N);
    vector<ll> value(N);

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << fbu(W,value, weight);
    return 0;
}