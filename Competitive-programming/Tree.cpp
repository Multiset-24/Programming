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

vector<vector<int>> g;        // Adjacency list
vector<bool> isleaf;          // Whether a node is a leaf
vector<int> depth;            // Depth of each node
vector<int> subtree_size;     // Subtree size of each node
vector<int> parent;           // Parent of each node
vector<int> no_of_child;      // Number of children for each node

void dfs(int r, int p, int d) {
    int child = 0;

    subtree_size[r] = 1;      // Initialize subtree size of current node
    depth[r] = d;             // Set depth of current node
    parent[r] = p;            // Set parent of current node

    for (auto c : g[r]) {
        if (c != p) {         // Avoid processing the parent node
            child++;
            dfs(c, r, d + 1); // Recursive call for child nodes
            subtree_size[r] += subtree_size[c]; // Add child's subtree size
        }
    }
    if (child == 0) isleaf[r] = true; // If no child, mark as leaf
    no_of_child[r] = child;           // Store number of children
}

void jarvis() {
    int n;
    cin >> n;

    g.assign(n + 1, vector<int>());
    isleaf.assign(n + 1, false);
    depth.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    subtree_size.assign(n + 1, 0);
    no_of_child.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);// if root not mentioned then start with 1 due to overflow cases 

    // Debugging outputs
    cout << "Subtree sizes: "; print_vector(subtree_size);
    cout << "Depths: "; print_vector(depth);
    cout << "Parents: "; print_vector(parent);
    cout << "Number of children: "; print_vector(no_of_child);
    cout << "Leaf nodes: "; 
    for (int i = 1; i <= n; i++) {
        if (isleaf[i]) cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
