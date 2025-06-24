#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7;
int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int leaves = 0;
    int left = -1, right = -1;
    auto dfs = [&](auto self, int x, int y) -> int {
        int cnt = 0;
        for(auto it : g[x]) if (it != y) {
            cnt += 1;
        }
        if (cnt == 0) {
            leaves += 1;
            return 1;
        }
        if (cnt == 1) {
            for (auto it : g[x]) if (it != y) return 1 + self(self, it, x);
        }
        for(auto it : g[x]) if (it != y) {
            int got = self(self, it, x);
            if (left == -1) left = got;
            else right = got;
        }
        return left + right + 1;
    };
    dfs(dfs, 0, 0);


    if (leaves > 2) {
        cout << 0 << '\n';
        return;
    }
    else if(leaves == 1) {
        cout << power(2, n) << '\n';
        return;
    }
    if (left > right) swap(left, right);
    int ans = power(2, n - 2 * left);
    if (left == right) {
        ans = ans * 2 % mod;
    }
    else {
        ans = (ans + power(2, n - 2 * left - 1)) % mod;
    }

    cout << ans << '\n';
}

int32_t main() {
    int t; cin >> t;
    while(t--) solve();
}
