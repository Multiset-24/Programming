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

const int INF = 1e18;
void jarvis()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x:a)cin>>x;
    int g_all = a[0];
    for (int i = 1; i < n; i++) {
        g_all = __gcd(g_all, a[i]);
    }
    vector<int> b(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        if (b[i]/g_all == 1) 
            cnt1++;
    }
    if (cnt1 > 0) {
        cout << (n - cnt1) << endl;
        return;
    }
    vector<int> unq = b;
    sort(unq.begin(), unq.end());
    auto it=unique(unq.begin(), unq.end());
    int max_val = unq.back();
    vector<int> dist(max_val + 1, INF);
    queue<int> q;
    for (int i=0;i<it-unq.begin();i++) {
        int v=unq[i];
        dist[v] = 0;
        q.push(v);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int dv = dist[v];
        for (auto w : unq) {
            int u = __gcd(v, w);
            if (dist[u] > dv + 1) {
                dist[u] = dv + 1;
                q.push(u);
            }
        }
    }
    int d = dist[g_all];  
    int minop = n + d - 1;
    cout << minop << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>v={1,1,1,1,2,2,3,4,4,5};
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}