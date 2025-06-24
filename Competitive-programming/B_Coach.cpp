#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

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

class Dsu {
public:
    vector<int> par, rank;
    Dsu(int n) {
        par.resize(n + 1);
        rank.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int x) {
        return par[x] = (par[x] == x ? x : find(par[x]));
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            par[y] = x;
            rank[x] += rank[y];
        }
    }
};
void jarvis() {
    int n, m;
    cin >> n >> m;
    Dsu d(n);
    vector<bool> used(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d.unite(u, v);
        used[u] = used[v] = true;
    }
    map<int, vector<int>> groups;
    for (int i = 1; i <= n; i++) {
        groups[d.find(i)].push_back(i);
    }
    vector<vector<int>> ones, twos, threes;
    for (auto &it : groups) {
        auto v=it.second;
        if (v.size() > 3) {
            cout << -1 << endl;
            return;
        }
        if (v.size() == 3) threes.push_back(v);
        else if (v.size() == 2) twos.push_back(v);
        else ones.push_back(v);
    }
    vector<vector<int>> res;
    for (auto &tw : twos) {
        if (ones.empty()) {
            cout << -1 << endl;
            return;
        }
        tw.push_back(ones.back()[0]);
        ones.pop_back();
        res.push_back(tw);
    }
    if (ones.size() % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < ones.size(); i += 3) {
        res.push_back({ones[i][0], ones[i + 1][0], ones[i + 2][0]});
    }
    for (auto &v : threes) res.push_back(v);
    for (auto &group : res) {
        for (int x : group) cout << x << " ";
        cout << endl;
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
