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

struct S { 
    int u, p, d,prefix, min_up, max_up;
};
void jarvis()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n+1);
    vector<long long> ans(n+1);
    vector<S> st;
    st.push_back({1, 0, 0, a[1], 0LL, 0LL});
    while (!st.empty()) {
        auto cur = st.back();
        st.pop_back();
        int u = cur.u, p = cur.p, d = cur.d;
        int prefix = cur.prefix;
        int min_up = cur.min_up;
        int max_up = cur.max_up;
        if (d % 2 == 0) {
            ans[u] = prefix - min_up;
        } else {
            ans[u] = max_up - prefix;
        }
        int new_min = min(min_up, prefix);
        int new_max = max(max_up, prefix);
        for (int v : adj[u]) if (v != p) {
            int nd = d + 1;
            int bv = (nd % 2 == 0 ? a[v] : -a[v]);
            int npref = prefix + bv;
            st.push_back({v, u, nd, npref, new_min, new_max});
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}