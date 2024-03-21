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
    
    int n, k;
    read(n,k);

    vector<int> a(n);

    for(int i=0; i<n; i++) {
        read(a[i]);
    }

    u_mp<int,int> mp;

    for(int i=0; i<a.size(); i++) {
        mp[a[i]] = i+1;
    }

    if(mp.size() < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int i = 0;
        for(auto x: mp) {
            cout<<x.second<<" ";
            i++;
            if(i == k) {
                break;
            }
        }
    }

    

    return 0;
}