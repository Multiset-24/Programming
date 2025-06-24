#include <bits/stdc++.h>
using namespace std;
//corrected syntax with gpt
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

int base[2][2] = {{1, 4},
                  {3, 2}};

pair<int, int> put(int strt, int sz, int d)
{
    if (sz == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (base[i][j] + strt - 1 == d)
                    return {i, j};
            }
        }
    }
    int half = sz / 2;
    int cell_sz = half * half;
    if (d <= strt + cell_sz - 1)
    {
        return put(strt, half, d);
    }
    else if (d <= strt + 2 * cell_sz - 1)
    {
        pair<int, int> p = put(strt + cell_sz, half, d);
        return {p.first + half, p.second + half};
    }
    else if (d <= strt + 3 * cell_sz - 1)
    {
        pair<int, int> p = put(strt + 2 * cell_sz, half, d);
        return {p.first + half, p.second};
    }
    else
    {
        pair<int, int> p = put(strt + 3 * cell_sz, half, d);
        return {p.first, p.second + half};
    }
}

int get(int x, int y, int strt, int sz) {
    int half = sz / 2;
    int cell_sz = half * half;
    if (sz == 2) {
        // Using x and y as 0-indexed; base[i][j] corresponds to element in position (i, j)
        return strt + base[x][y] - 1;
    }
    
    // Determine in which quadrant the cell (x, y) lies.
    // Note the order:
    // Q1: Top-Left      -> no offset (x, y)
    // Q2: Bottom-Right  -> offset (+half, +half)
    // Q3: Bottom-Left   -> offset (+half, 0)
    // Q4: Top-Right     -> offset (0, +half)
    if (x < half && y < half) {
        // Top-Left (Q1)
        return get(x, y, strt, half);
    } else if (x >= half && y >= half) {
        // Bottom-Right (Q2)
        return get(x - half, y - half, strt + cell_sz, half);
    } else if (x >= half && y < half) {
        // Bottom-Left (Q3)
        return get(x - half, y, strt + 2 * cell_sz, half);
    } else { 
        // Top-Right (Q4)
        return get(x, y - half, strt + 3 * cell_sz, half);
    }
}

void jarvis()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "->")
        {
            int x, y;
            cin >> x >> y;
            // Convert 1-indexed input to 0-indexed before processing.
            cout << get(x - 1, y - 1, 1, 1 << n) << endl;
        }
        else if (s == "<-")
        {
            int d;
            cin >> d;
            pair<int, int> a = put(1, 1 << n, d);
            // Convert the result back to 1-indexed for printing.
            cout << a.first + 1 << " " << a.second + 1 << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--)
    {
        jarvis();
    }
    return 0;
}
