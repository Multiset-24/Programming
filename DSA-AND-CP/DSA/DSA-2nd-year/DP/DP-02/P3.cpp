#include <bits/stdc++.h>
using namespace std;
// DICE COMBINATIONS
#define mod 1000000007
vector<long long> dp;
int f(int n)
{
    long long c = 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != -1)
        return dp[n];
    for (int i = 1; i <= 6; i++)
    {
        if (n - i > 0)
        {
            c = (c % mod + f(n - i) % mod) % mod;
        }
        else if (n - i == 0)
            c++;
        else
            break;
    }

    return dp[n] = c;
}

int fbt(int n)
{
    dp[0] = 1;

    for (int k = 1; k <= n; k++)
    {
        int c=0;
        for (int i = 1; i <= 6; i++)
        {
            if (k - i > 0)
            {
                c = (c % mod + dp[k - i] % mod) % mod;
            }
            else if (k - i == 0)
                c++;
            else
                break;
        }
        dp[k]=c;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    dp.clear();
    dp.resize(1000006, -1);
    cout << (fbt(n));
    return 0;
}