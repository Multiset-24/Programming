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

int n, m, k;

vector<vector<int>> g;
void jarvis()
{
    cin >> n >> m >> k;

    int t = n * m / k;
    int l = m / k;
    if (m % k == 0)
    {
        vector<int> f;
        vector<int> fi;
        for (int i = 1; i <= k; i++)
            f.push_back(i);
        for (int i = 2; i <= k; i++)
            fi.push_back(i);
        fi.push_back(1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i & 1)
                {
                    cout << fi[j % k] << " ";
                }
                else
                {
                    cout << f[j % k] << " ";
                }
            }
            cout << endl;
        }
    }
    else
    {
        int nm = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                cout << nm << " ";
                nm++;
                if (nm == k + 1)nm = 1;
            }
            cout << endl;
        }
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