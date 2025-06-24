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

void jarvis()
{
    int n;
    cin >> n;

    vector<vector<char>> g(n, vector<char>(n, '.'));

    if (n & 1)
    {
        for (int l = n; l >= 0; l--)
        {
            for (int i = n - l; i < l; i++)
            {
                for (int j = n - l; j < l; j++)
                {
                    if ((l & 1) != 0 && (i == n - l || i == l - 1 || j == n - l || j == l - 1))
                    {
                        g[i][j] = '#';
                    }
                    else
                    {
                        g[i][j] = '.';
                    }
                }
            }
        }
    }
    else
    {
        for (int l = n; l >= 0; l--)
        {
            for (int i = n - l; i < l; i++)
            {
                for (int j = n - l; j < l; j++)
                {
                    if ((l & 1) == 0 && (i == n - l || i == l - 1 || j == n - l || j == l - 1))
                    {
                        g[i][j] = '#';
                    }
                    else
                    {
                        g[i][j] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}