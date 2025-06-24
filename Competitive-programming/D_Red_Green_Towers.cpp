#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

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

int R, G, height;

void jarvis() {
    cin >> R >> G;
    int total = R + G;
    vector<int> dp(R + 1, 0);
    dp[0] = 1;
    
    int maxHeight = 0;
    for (int h = 1; h * (h + 1) / 2 <= total; ++h) {
        maxHeight = h;
        for (int r = R; r >= h; --r) {
            dp[r] = (dp[r] + dp[r - h]) % mod;
        }
    }
    height = maxHeight;
    int sumWays = 0;
    for (int r = 0; r <= R; ++r) {
        int used = height * (height + 1) / 2;
        if (r + G >= used) sumWays = (sumWays + dp[r]) % mod;
    }
    cout << sumWays << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q = 1;
    while (q--) {
        jarvis();
    }
    return 0;
}
