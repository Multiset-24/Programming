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

// Enter your main logic here !!
int dp[501][125251]; // Adjusted size to avoid overflow

int rec(int i, int curr_sum, int target, vector<int>& num) {
    if (curr_sum == target) return 1;
    if (curr_sum > target) return 0;
    if (i >= (int)num.size()) return 0;

    if (dp[i][curr_sum] != -1) return dp[i][curr_sum];
    int take = rec(i + 1, curr_sum + num[i], target, num);
    int not_take = rec(i + 1, curr_sum, target, num);

    return dp[i][curr_sum] = (take % mod + not_take % mod) % mod;
}

void jarvis() {
    int n;
    cin >> n;

    int sum = (n * (n + 1)) / 2;

    if (sum & 1) {
        cout << 0 << endl;
        return;
    }
    memset(dp, -1, sizeof(dp));
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }

    cout << rec(0, 0, sum / 2, num) * 500000004 % mod << endl; // Multiplying by modular inverse of 2
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