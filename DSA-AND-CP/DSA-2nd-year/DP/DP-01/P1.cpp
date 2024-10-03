#include <bits/stdc++.h>
using namespace std;

// frog-2----------->top to bottom approach
vector<int> heights;
int k;
vector<int> dp;
int f(int i)
{
    if (i >= heights.size())
        return INT_MAX;
    if (i == heights.size() - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i + j >= heights.size())
            break;
        ans = min(ans, abs(heights[i] - heights[i + j]) + f(i + j));
    }
    dp[i] = ans;
    return dp[i];
}

int fbu()
{
    int n = heights.size();
    dp.resize(100005, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j >= heights.size())
                break;
            dp[i] = min(dp[i], abs(heights[i] - heights[i + j]) + dp[i + j]);
        }
    }
    return dp[0];
}
int main()
{
    int n;
    cin >> n >> k;
    heights.clear();
    heights.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // cout << f(0);

    cout<<fbu();
    return 0;
}