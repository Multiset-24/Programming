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
    int x, y;
    cin >> x >> y;
    x = (x + mod) % mod;
    y = (y + mod) % mod;
    int n;
    cin >> n;
    int z = (y - x + mod) % mod;
    int k = (-z + mod) % mod;
    switch (n % 6)
    {
    case 1:
        cout << x << endl;
        break;
    case 2:
        cout << y << endl;
        break;
    case 3:
        cout << z << endl;
        break;
    case 4:
        cout << (-x + mod) % mod << endl;
        break;
    case 5:
        cout << (-y + mod) % mod << endl;
        break;
    case 0:
        cout << k << endl;
        break;
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