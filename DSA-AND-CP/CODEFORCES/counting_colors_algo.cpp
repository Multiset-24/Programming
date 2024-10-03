#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#define print_set(s)             \
    {                            \
        cout << #s << " = {";    \
        for (auto &elem : s)     \
            cout << elem << " "; \
        cout << "}" << endl;     \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_set(s)
#define print_2dvector(v)
#endif
#define endl '\n'

// DP table for memoization
vector<vector<vector<int>>> dp;

// Function to calculate number of valid sequences
int rec(int brick_left, int colors, int diff, int last) {
    if (brick_left == 0 && diff == 0) {
        return 1;
    }

    if (brick_left == 0 || diff < 0) return 0;

    if (dp[brick_left][diff][last + 1] != -1) {
        return dp[brick_left][diff][last + 1];
    }

    int ans = 0;
    for (int i = 0; i < colors; i++) {
        if (last == i || last == -1) {
            ans = (ans + rec(brick_left - 1, colors, diff, i)) % mod;
        } else {
            ans = (ans + rec(brick_left - 1, colors, diff - 1, i)) % mod;
        }
    }

    return dp[brick_left][diff][last + 1] = ans;
}

void jarvis() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k == 0) {
        cout << m << endl;
        return;
    }

    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
    cout << rec(n, m, k, -1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}

