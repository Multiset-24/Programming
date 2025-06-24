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

set<pair<int, int>> smoke;
int offset_x = 0, offset_y = 0;
void insert(int x, int y)
{
    smoke.insert({x - offset_x, y - offset_y});
}
void shift(int dx, int dy)
{
    offset_x += dx;
    offset_y += dy;
}
bool exists(int x, int y)
{
    return smoke.count({x - offset_x, y - offset_y}) > 0;
}

void jarvis()
{
    int n, r, c;
    cin >> n >> r >> c;

    string s;
    cin >> s;
    insert(0, 0);
    int sx = 0, sy = 0;

    for (int i = 1; i <= n; i++)
    {
        switch (s[i-1])
        {
        case 'W':
            shift(0, -1);break;
        case 'S':
            shift(1, 0);break;
        case 'N':
            shift(-1, 0);break;
        case 'E':
            shift(0, +1);break;
        }
        insert(sx, sy);
        if (exists(r, c))
            cout << "1";
        else
            cout << '0';
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