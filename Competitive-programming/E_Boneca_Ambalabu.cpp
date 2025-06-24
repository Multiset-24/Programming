#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long 
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#else
#define print_vector(v)
#endif
#define endl '\n'

void jarvis() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    int B = 60;
    vector<int> cnt(B, 0);
    for (int x : a) {
        for (int b = 0; b < B; b++) {
            if (x & (1LL << b))
                cnt[b]++;
        }
    }
    
    int max_sum = 0;
    for (int x : a) {
        int curr_sum = 0;
        for (int b = 0; b < B; b++) {
            int p = 1LL << b;
            if (x & (1LL << b))
                curr_sum += (n - cnt[b]) * p; 
            else
                curr_sum += cnt[b] * p;       
        }
        max_sum = max(max_sum, curr_sum);
    }
    
    cout << max_sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        jarvis();
    }
    return 0;
}
