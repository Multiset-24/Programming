#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'
int dp[100][10000];
bool rec(vector<int> &num, int i, int k)
{
    if (k == 0)
        return true;
    if (i >= num.size())
        return false;

    if (dp[i][k] != -1)
        return dp[i][k];

    bool not_take = rec(num, i + 1, k);
    bool take = false;
    if (k - num[i] >= 0)
    {
        take = rec(num, i + 1, k - num[i]);
    }

    return dp[i][k] = take || not_take;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> num(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }

        memset(dp, -1, sizeof(dp));
        while (q--)
        {
            int k;
            cin >> k;
            if (rec(num, 0, k))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}