#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

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

int n, k;
vector<int> num;

bool check(int x) {
    int cnt = 0;
    unordered_map<int, int> freq;
    int needed = x;
    
    int l = 0;
    for (int r = 0; r < n; ++r) {
        if (num[r] < x)
            freq[num[r]]++;

        if (freq.size() == x) {
            cnt++;
            freq.clear();
        }
    }

    return cnt >= k;
}

void jarvis() {
    cin >> n >> k;
    num.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int lo = 0, hi = n;
    int ans = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
