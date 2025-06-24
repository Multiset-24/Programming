#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &x : v) cout << x << " "; cout << "]\n"; }
#else
#define print_vector(v)
#endif
#define endl '\n'

void jarvis() {
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    // dp_above[j][r] = number of ways to reach (i-1, j) with r consecutive rights
    vector<vector<int>> dp_above(m, vector<int>(K+1, 0));
    vector<vector<int>> dp_cur  (m, vector<int>(K+1, 0));

    // --- Row 0 initialization ---
    if (grid[0][0] == 0) {
        dp_above[0][0] = 1;  // start at (0,0) with 0 rights
    }
    for (int j = 1; j < m; j++) {
        if (grid[0][j] == 1) {
            // blocked
            for (int r = 0; r <= K; r++) 
                dp_above[j][r] = 0;
        } else {
            // can only come by horizontal from (0, j-1)
            for (int r = 1; r <= K; r++) {
                dp_above[j][r] = dp_above[j-1][r-1];
            }
            dp_above[j][0] = 0;  // no vertical on first row
        }
    }

    // --- Process rows 1..n-1 ---
    for (int i = 1; i < n; i++) {
        // prepare column-wise vertical sums from previous row
        vector<int> colSum(m, 0);
        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int r = 0; r <= K; r++) {
                s = (s + dp_above[j][r]) % mod;
            }
            colSum[j] = s;
        }

        // reset dp_cur
        for (int j = 0; j < m; j++) 
            for (int r = 0; r <= K; r++) 
                dp_cur[j][r] = 0;

        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                // blocked cell: all ways = 0
                continue;
            }
            // 1) vertical move: from (i-1, j), resets right-count to 0
            dp_cur[j][0] = colSum[j];

            // 2) horizontal moves: extend right-chain within this row
            if (j > 0) {
                for (int r = 1; r <= K; r++) {
                    dp_cur[j][r] = dp_cur[j-1][r-1];
                }
            }
        }
        // swap dp_above and dp_cur for next iteration
        dp_above.swap(dp_cur);
    }

    // answer = sum of all states at (n-1, m-1) over consecutive-rights = 0..K
    int answer = 0;
    for (int r = 0; r <= K; r++) {
        answer = (answer + dp_above[m-1][r]) % mod;
    }
    cout << answer << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) 
        jarvis();
    return 0;
}
