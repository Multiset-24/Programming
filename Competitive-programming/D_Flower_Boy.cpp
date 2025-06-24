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

void jarvis() {
    int n, m;
    cin >> n >> m;
    vector<int>a(n+1), b(m+2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    vector<int> fwd(m+1, INF);
    fwd[0] = 0;
    int ptr = 1;
    for(int i = 1; i <= m; i++) {
        while(ptr <= n && a[ptr] < b[i]) ptr++;
        if(ptr <= n) {
            fwd[i] = ptr;
            ptr++;
        } 
    }
    if(fwd[m] != INF) {
        cout << 0 << endl;
        return;
    }
    vector<int> bwd(m+2, 0);
    bwd[m+1] = n + 1;
    ptr = n;
    for(int i = m; i >= 1; i--) {
        while(ptr >= 1 && a[ptr] < b[i]) ptr--;
        if(ptr >= 1) {
            bwd[i] = ptr;
            ptr--;
        } 
    }
    int ans = INF;
    for(int t = 1; t <= m; t++) {
        if(fwd[t-1] < bwd[t+1]) {
            ans = min(ans, b[t]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        jarvis();
    }
    return 0;
}
