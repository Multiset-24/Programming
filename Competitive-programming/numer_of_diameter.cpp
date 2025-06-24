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
vector<int> depth;
vector<int> parent;
vector<int> noc; // no_of_children_in_subtree_having_specific_distance_from_root_node
const int INF = 1e10;

int child_distance = INF;

void dfs(int node, int p, int d, int cd) {
    depth[node] = d;
    parent[node] = p;

    if(depth[node]==cd)noc[node]=1;

    for (auto v : g[node]) {
        if (v != p) {
            dfs(v, node, d + 1, cd);
            noc[node]+=noc[v];
        }
    }
}

void jarvis() {
    int n;
    cin >> n;

    g.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    noc.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0, child_distance);
    int end_point = 1;

    for (int i = 1; i <= n; i++)
        if (depth[i] > depth[end_point])
            end_point = i;

    dfs(end_point, 0, 0, child_distance);
    end_point = 1;

    for (int i = 1; i <= n; i++)
        if (depth[i] > depth[end_point])
            end_point = i;

    int lim = depth[end_point] / 2;

    int center = end_point;
    for (int i = 0; i < lim; i++) {
        center = parent[center];
    }

    int center_02 = 0;

    bool having_two_centers = false;

    if (depth[end_point] & 1) {
        having_two_centers = true;
        center_02 = parent[center];
    }

    int no_of_diameters = 0;

    if (having_two_centers) {
        dfs(center, center_02, 0, lim);
        int p=noc[center];
        dfs(center_02,center,0,lim);
        int q=noc[center_02];

        cout<<p*q<<endl;
    } else {
        dfs(center, 0, 0, lim);
        vector<int> temp;

        for (auto v : g[center]) {
            temp.push_back(noc[v]);
        }
        vector<int> prefix_sum(temp.size() + 1, 0);

        for (int i = 1; i <= temp.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + temp[i - 1];
        }

        int ans = 0;

        for (int i = temp.size(); i >= 1; i--) {
            ans += (prefix_sum[i - 1] * temp[i - 1]);
        }

        cout << ans << endl;
    }
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
