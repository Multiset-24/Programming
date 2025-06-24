#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
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
int cnt=0;
// Recursive function to calculate the number of ways
int rec(vector<int>& s, int n, int val,vector<int>&dp) {
    if (val > n)
        return 0;
    if (val == n)
        return 1;
    
    if(dp[val]!=-1) return dp[val];
    cnt++;
    int result = 0;
    for (int j = 0; j < s.size(); j++) {
        result=(result%mod+rec(s, n, val + s[j],dp)%mod);
        result=result%mod;
    }
    
    return dp[val]=result%mod;
}

void jarvis() {
    int n, k;
    cin >> n >> k;
    set<int> temp;

    while (k--) {
        int l, r;
        cin >> l >> r;
        for(int i=l;i<=r;i++)temp.insert(i);
    }

    vector<int> s(temp.begin(), temp.end());
    vector<int>dp(n+1,-1);
    cout << rec(s, n, 1,dp) <<" "<<cnt<<endl;
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