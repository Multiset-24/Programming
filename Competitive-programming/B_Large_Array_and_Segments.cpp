#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Debugging macro
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

void jarvis() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    
    vector<long long> a(n);
    long long S = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S += a[i];
    }
    
    vector<long long> prefix(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + a[i];
    }
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        long long partial = S - prefix[i];
        if (partial >= x) {
            ans += k;
        } else {
            long long rem = x - partial;
            long long m = (rem + S - 1) / S;
            if (m < k) {
                ans += (k - m);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
