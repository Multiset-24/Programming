#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int N, K, NK;
vector<vector<int>> tree;

// DFS returns the pending chain length from node v upward.
// If a valid decomposition is impossible, it prints "No" and exits.
int dfs(int v, int parent) {
    int pending = 1;           // Count the current vertex.
    int activeChildren = 0;    // Count how many children contribute a nonzero pending value.
    
    for (int u : tree[v]) {
        if (u == parent) continue;
        int x = dfs(u, v);
        if (x > 0) {           // This child contributed a pending chain.
            pending += x;
            activeChildren++;
        }
    }
    
    // If the pending chain is too long, it's impossible.
    if (pending > K) {
        cout << "No" << endl;
        exit(0);
    }
    // If the chain is not complete and more than one child contributes,
    // that means the chain branches.
    if (pending < K && activeChildren >= 2) {
        cout << "No" << endl;
        exit(0);
    }
    // If we reached exactly K vertices, remove this subtree.
    if (pending == K) return 0;
    
    return pending;
}

void solve() {
    cin >> N >> K;
    NK = N * K;
    
    tree.assign(NK + 1, vector<int>());
    
    // There are NK-1 edges.
    for (int i = 1; i < NK; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // Run DFS from node 1.
    int res = dfs(1, -1);
    // For a full decomposition, the root must also be removed.
    if (res != 0) {
        cout << "No" << endl;
    } else {    
        cout << "Yes" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
