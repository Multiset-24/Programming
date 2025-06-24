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

    subtree_size[r] = 1;     
    depth[r] = d;             
    parent[r] = p;            

    for (auto c : g[r]) {
        if (c != p) {        
            child++;
            dfs(c, r, d + 1);
            subtree_size[r] += subtree_size[c]; 
        }
    }
    if (child == 0) isleaf[r] = true; 
    no_of_child[r] = child;           
}

void jarvis() {
    int n;
    cin >> n;

    g.assign(n + 1, vector<int>());
    isleaf.assign(n + 1, false);
    depth.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    subtree_size.assign(n + 1, 0);
    no_of_child.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    int eod=0;
    int eode=0;

    for(int i=1;i<=n;i++){
        int d=depth[i];

        if(d>eode){
            eode=d;
            eod=i;
        }
    }

    dfs(eod,0,0);

    int other_end_of_diameter=0;
    int dis=0;

    for(int i=1;i<=n;i++){
        if(depth[i]>dis){
            other_end_of_diameter=i;
            dis=depth[i];
        }
    }

    int curr=other_end_of_diameter;
    while(curr!=0){
        cout<<curr<<" ";
        curr=parent[curr];
    }

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
