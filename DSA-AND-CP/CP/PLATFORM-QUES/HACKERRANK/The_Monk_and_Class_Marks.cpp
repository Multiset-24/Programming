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
    
    map<int,multiset<string>> m;
    int n;
    read(n);
    for(int i=0; i<n; i++) {
        string s;
        int x;
        read(s, x);
        x=-x;//trick to sort in descending order
        m[x].insert(s);
    }

    
    for(auto i: m) {
        for(auto j: i.second) {
            cout << j << " " << -i.first << endl;//trick to print in ascending order
        }
    }
    return 0;
}