#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

// Debugging macros
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#endif

int n, m;
vector<int> broken;      // broken[row] as bitmask
vector< vector<int> > dp;

void dfs_transition(int col, int cur_mask, int next_mask, int row, int init_mask) {
    if (col >= m) {
        // current row filled; accumulate ways
        dp[row+1][next_mask] = (dp[row+1][next_mask] + dp[row][init_mask]) % mod;
        return;
    }
    if (cur_mask & (1LL << col)) {
        // already filled, move on
        dfs_transition(col+1, cur_mask, next_mask, row, init_mask);
    } else {
        // try vertical domino
        if (row+1 < n) {
            dfs_transition(col+1,
                           cur_mask | (1LL << col),
                           next_mask | (1LL << col),
                           row, init_mask);
        }
        // try horizontal domino
        if (col+1 < m && !(cur_mask & (1LL << (col+1)))) {
            dfs_transition(col+2,
                           cur_mask | (1LL << col) | (1LL << (col+1)),
                           next_mask,
                           row, init_mask);
        }
    }
}

void jarvis() {
    cin >> m >> n;
    broken.assign(n, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') broken[i] |= (1LL << j);
        }
    }
    dp.assign(n+1, vector<int>(1<<m, 0));
    // base case: before any row, current mask must be exactly broken[0]
    dp[0][broken[0]] = 1;

    for (int row = 0; row < n; row++) {
        for (int mask = 0; mask < (1<<m); mask++) {
            if (dp[row][mask] == 0) continue;
            // mask must include broken bits
            if ((mask & broken[row]) != broken[row]) continue;
            // transition from this state
            dfs_transition(0, mask, broken[row+1 < n ? row+1 : row] * 0, row, mask);
            // Note: for last row, broken[next] = 0 so next_mask starts at 0
        }
    }

    // answer: all rows processed, mask=0 for imaginary row n
    cout << dp[n][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;  // agar multiple testcases ho
    while (q--) jarvis();
    return 0;
}
