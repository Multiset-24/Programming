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
// #define endl '\n'

vector<vector<int>> g;
set<int> group[2];
set<pair<int, int>> original_edges;
void dfs(int u, int gr, int p)
{
    group[gr].insert(u);
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, 1 - gr, u);
        }
    }
}

set<pair<int, int>> possible()
{
    set<pair<int, int>> edges;
    for (auto u : group[0])
    {
        for (auto v : group[1])
        {
            int a = min(u, v);
            int b = max(u, v);
            if (original_edges.find({a, b}) == original_edges.end())
            {
                edges.insert({a, b});
            }
        }
    }
    return edges;
}

void jarvis()
{
    int n;
    cin >> n;

    g.assign(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        original_edges.insert({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    set<pair<int, int>> edges = possible();

    int total = edges.size();

    bool turn = 1;

    if (total & 1)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
        turn = 0;
    }

    while (!edges.empty())
    {
        if (turn)
        {
            pair<int, int> p = *edges.begin();
            cout << p.first << " " << p.second << endl;
            edges.erase({p.first, p.second});
            turn = !turn;
        }
        else
        {
            int u, v;
            cin >> u >> v;
            if (u == -1)
            {
                return;
            }
            else
            {
                edges.erase({u, v});
                edges.erase({v, u});
                turn = !turn;
            }
        }
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