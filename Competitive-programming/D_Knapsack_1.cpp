#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

typedef pair<int, int> obj;

int dp[105][100010];
vector<obj> options;

int knapsack(int i, int wt_left)
{   
    if (i < 0 || wt_left<=0)
        return 0;

    if (dp[i][wt_left] != -1)
        return dp[i][wt_left];

    int ans = knapsack(i - 1, wt_left);
    if (i>=0 && wt_left - options[i].first >= 0)
        ans = max(ans, options[i].second + knapsack(i - 1, wt_left - options[i].first));

    return dp[i][wt_left] = ans;
}
void jarvis()
{
    int n, w;
    cin >> n >> w;

    options.clear();

    for (int i = 0; i < n; i++)
    {
        int wi, vi;
        cin >> wi >> vi;
        options.push_back({wi, vi});
    }

    cout<<knapsack(n-1,w);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}