#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

vector<vector<int>> g;
vector<int> vis;
int edges_count=0;
int node_count=0;

void dfs(int node) {
    vis[node] = true;
    for (int neighbor : g[node]) {
        edges_count++;
        if (!vis[neighbor]) {
            node_count++;
            dfs(neighbor);
        }
    }
}

void jarvis() {
    int n, m;
    cin >> n >> m;

    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            edges_count=0;
            node_count=1;
            dfs(i);edges_count>>=1;
            ans+=(edges_count-node_count+1);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}