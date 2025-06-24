#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define INF LLONG_MAX

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

int n;
vector<int> slime_size;
vector<int> prefix_sizes;
vector<vector<int>> dp;

int solve(int l, int r) {
    if (l == r) return 0;
    
    if (dp[l][r] != -1) return dp[l][r];

    int ans = INF;
    for (int mid = l; mid < r; mid++) {
        int total_cost = prefix_sizes[r] - prefix_sizes[l - 1];
        ans = min(ans, total_cost + solve(l, mid) + solve(mid + 1, r));
    }

    return dp[l][r] = ans;
}

void jarvis() {
    cin >> n;
    slime_size.assign(n + 1, 0);
    prefix_sizes.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        cin >> slime_size[i];
        prefix_sizes[i] = slime_size[i] + prefix_sizes[i - 1];
    }

    cout << solve(1, n) << endl;
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
