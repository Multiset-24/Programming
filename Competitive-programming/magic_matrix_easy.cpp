#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { \
    cout << #v << " = ["; \
    for (auto &x : v) cout << x << " "; \
    cout << "]" << endl; \
}
#else
#define print_vector(v)
#endif

#define endl '\n'

void jarvis() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = *min_element(v[i].begin(), v[i].end());
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++) {
        b[j] = v[0][j] - a[0];
        if (b[j] < 0) {  
            cout << "No\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] + b[j] != v[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        jarvis();
    }
    return 0;
}
