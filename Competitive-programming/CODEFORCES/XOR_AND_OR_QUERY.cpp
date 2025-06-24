#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

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

void jarvis()
{
    int n;
    cin >> n;
    vector<vector<int>> prefixSum(32, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int cnt = 0;
        while (a > 0)
        {
            prefixSum[cnt][i] = a % 2;
            a>>=1;
            cnt++;
        }
    }
    for (int j = 0; j <31; j++)
    {
        for (int i =1; i <=n; i++)
            prefixSum[j][i] += prefixSum[j][i - 1];
    }

    int q;
    cin >> q;
    vector<int> ans;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x1 = 0, x2 = 0, x3 = 0;

        int nb = (r - l + 1);
        for (int i = 0; i < 32; i++)
        {
            int x =  prefixSum[i][r] - prefixSum[i][l - 1];

            if (x < (nb / 2.0))
                x1 += (1LL << i);
            if (x != nb)
                x2 += (1LL << i);
            if (x)
                x3 += (1LL << i);
        }

        ans.push_back(x1 + x2 + x3);
    }

    for (auto e : ans)
    {
        cout << e << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}