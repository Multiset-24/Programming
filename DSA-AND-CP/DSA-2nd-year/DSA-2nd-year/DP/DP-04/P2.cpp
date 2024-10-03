#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/GNYR09F/cstart=40
// template
#define mod 1000000007
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define RF(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)

int dp[105][105][2];

int f(int n, int k, int last)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        if (k == 0)
            return 1;
        else
            return 0;
    }

    if(k<0) return 0;

    if (dp[n][k][last] != -1)
        return dp[n][k][last];
    if (last == 0)
    {
        dp[n][k][last] = f(n - 1, k, 0) + f(n - 1, k, 1);
    }
    else
    {
        dp[n][k][last] = f(n - 1, k, 0) + f(n - 1, k - 1, 1);
    }
    return dp[n][k][last];
}
int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        int num, n, k;
        cin >> num >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << num << " " << f(n, k, 0) + f(n, k, 1) << endl;
    }
    return 0;
}