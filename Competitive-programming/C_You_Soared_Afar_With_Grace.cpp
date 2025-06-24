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

void jarvis()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int,int> mp;
    for (int i = 0; i < n; i++) mp[a[i]] = b[i];

    int sc = 0;
    for (auto it : mp) {
        if (mp[it.second] != it.first) {
            cout << -1 << endl;
            return;
        } else if (it.first == it.second) {
            sc++;
        }
    }
    if ((n % 2 == 0 && sc >= 1) || (n % 2 == 1 && sc >= 2)) {
        cout << -1 << endl;
        return;
    }
    map<int,int> mpa, mpb;
    for (int i = 0; i < n; i++) {
        mpa[a[i]] = i;
        mpb[b[i]] = i;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int u = mpb[x];
        int target = n - 1 - i;
        if (u == target) continue;  
        int v;
        if (mp[x] == x) {
            v = n / 2;
            if (u == v) continue;
        } else {
            v = target;
                ans.push_back({min(u, v), max(u, v)});
        swap(a[u], a[v]);
        swap(b[u], b[v]);
        mpa[a[u]] = u;  mpa[a[v]] = v;
        mpb[b[u]] = u;  mpb[b[v]] = v;
    }
    cout << ans.size() << endl;
    for (auto &p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
