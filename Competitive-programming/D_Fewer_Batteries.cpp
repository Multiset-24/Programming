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
typedef pair<int,int> state;

int n, m;
vector<int> b;
vector<vector<state>> g;
const int INF = 1e18;
bool check(int F) {
    vector<int> sum(n+1, -INF);
    sum[1] = b[1];
    for (int i = 1; i <= n; i++) {
        if (sum[i] < 0) continue;
        int cap = sum[i];
        for (auto &e : g[i]) {
            int j = e.first, w = e.second;
            if (w > F) continue;
            if (cap >= w) {
                sum[j] = max(sum[j], cap + b[j]);
            }
        }
    }
    return sum[n] >= 0;
}
void jarvis() {
    cin >> n >> m;
    b.assign(n+1, 0);
    g.assign(n+1, {});
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> allW;
    for (int i = 0; i < m; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        g[s].push_back({t, w});
        allW.push_back(w);
    }
    sort(allW.begin(), allW.end());
    allW.erase(unique(allW.begin(), allW.end()), allW.end());
    if (allW.empty()) {
        cout << (n == 1 ? 0 : -1) << endl;
        return;
    }
    int lo = 0, hi = (int)allW.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(allW[mid])) {
            ans = allW[mid];
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
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