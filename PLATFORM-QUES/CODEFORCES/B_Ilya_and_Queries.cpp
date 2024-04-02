#include <bits/stdc++.h>
using namespace std;

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    read(s);
    int n = s.size();
    int q;
    read(q);

    //precompute the answer for each query
    vector<int> ans(n, 0);
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] + (s[i] == s[i-1]);
    }
    while(q--){
        int l, r;
        read(l, r);
        //brute force solution-> O(n*q)
        // l--; r--;
        // int ans = 0;
        // for(int i = l; i < r; i++){
        //     if(s[i] == s[i+1]){
        //         ans++;
        //     }
        // }

        //optimized solution-> O(q)
        cout<<ans[r-1] - ans[l-1]<<endl;
    }
    return 0;
}