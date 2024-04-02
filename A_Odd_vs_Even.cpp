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

pair<int, int> countDivisors(int n) {
    int odd = 0;
    int even = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }
    return make_pair(odd, even);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    read(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        read(a[i]);
    }

    for (int i = 0; i < n; i++) {
        pair<int, int> counts = countDivisors(a[i]);
        cout << "Number " << a[i] << " has " << counts.first << " odd divisors and " << counts.second << " even divisors." << endl;
    }
    
    return 0;
}