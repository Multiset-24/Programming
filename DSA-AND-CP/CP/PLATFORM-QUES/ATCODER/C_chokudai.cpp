#include <bits/stdc++.h>
using namespace std;
//LINK: https://atcoder.jp/contests/abc211/tasks/abc211_c
#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

vector<vector<int>>dp(10005, vector<int>(10, -1));
// Function to calculate the number of ways to form the string "chokudai" recursively

int solve_dp(string s, string t, int i, int j) {
    if(dp[i][j]!=-1) return dp[i][j];
    if(j == (int)t.size()) {
        return 1;
    }
    if(i == (int)s.size()) {
        return 0;
    }
    if(s[i] == t[j]) {
        return dp[i][j]=(solve_dp(s, t, i+1, j+1) + solve_dp(s, t, i+1, j)) % mod;
    }
    return dp[i][j]=solve_dp(s, t, i+1, j);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s ;
    read(s);
    string t = "chokudai";
    dp.resize(s.size()+1, vector<int>(10, -1));
    // Recursive approach
    // cout << solve_dp(s, t, 0, 0) << endl;

    // Iterative approach

    vector<vector<int>>dp(s.size()+1, vector<int>(9, 0));
    for(int i = 0; i <= (int)s.size(); i++) {
        dp[i][0] = 1;//this is because we can always form an empty string
    }
    for(int i = 1; i <= (int)s.size(); i++) {
        for(int j = 1; j <= 8; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[s.size()][8] << endl;
    
    return 0;
}