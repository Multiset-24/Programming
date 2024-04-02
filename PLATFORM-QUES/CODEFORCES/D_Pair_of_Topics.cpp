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
    
    int n;
    read(n);
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        read(a[i]);
    }
    for(int i = 0; i < n; i++) {
        read(b[i]);
    }

    vector<int> diff(n);

    for(int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    sort(diff.begin(), diff.end());

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(diff[i] > 0) {
            int idx = lower_bound(diff.begin(), diff.end(), -diff[i] + 1) - diff.begin();
            ans += i - idx;
        }
    }

    cout << ans << endl;
    return 0;
}