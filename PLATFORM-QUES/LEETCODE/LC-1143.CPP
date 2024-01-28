#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define RF(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)

class Solution
{
public:
    vector<vector<int>> dp;
    int f(string text1, string text2, int i, int j)
    {
        if (i >= text1.length())
            return 0;
        if (j >= text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
            dp[i][j] = 1 + f(text1, text2, i + 1, j + 1);
        else
            dp[i][j] = max(f(text1, text2, i, j + 1), f(text1, text2, i + 1, j));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        dp.clear();
        dp.resize(1005, vector<int>(1005, -1));

        return f(text1, text2, 0, 0);
    }
};
int main()
{

    return 0;
}