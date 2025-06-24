#include <bits/stdc++.h>
using namespace std;

// Question -> find the height of the tree when rerooted at each node
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

int n;
vector<vector<int>> g;
vector<int> indp, outdp;

void indfs(int u, int p) {
    indp[u] = 0;
    for (auto v : g[u]) {
        if (v != p) {
            indfs(v, u);
            indp[u] = max(indp[u], indp[v] + 1);
        }
    }
}

void outdfs(int u, int p, int val) {
    outdp[u] = val;

    int max1 = -1, max2 = -1;
    for (auto v : g[u]) {
        if (v == p) continue;
        if (indp[v] > max1) {
            max2 = max1;
            max1 = indp[v];
        } else if (indp[v] > max2) {
            max2 = indp[v];
        }
    }

    for (auto v : g[u]) {
        if (v == p) continue;
        if (indp[v] == max1) {
            outdfs(v, u, max(outdp[u] + 1, max2 + 2));
        } else {
            outdfs(v, u, max(outdp[u] + 1, max1 + 2));
        }
    }
}

void jarvis() {
    cin >> n;

    g.assign(n + 1, vector<int>());
    indp.assign(n + 1, 0);
    outdp.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = 1;  // Choosing node 1 as the root
    indfs(root, -1);
    outdfs(root, -1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(indp[i], outdp[i]) << " ";
    }
    cout << endl;
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
