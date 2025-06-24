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

void jarvis()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ss(n+1, 0);
    for (int k = 1; k <= n; k++) {
        ss[k] = ss[k-1] + a[n-k+1];
    }
    vector<int> pm(n+1, 0);
    pm[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pm[i] = max(pm[i-1], a[i]);
    }
    vector<int> ans(n+1, 0);
    for (int k = 1; k <= n; k++) {
        int best = ss[k];
        if (k < n) {
            best = max(best, ss[k-1] + pm[n-k]);
        }
        ans[k] = best;
    }
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout <<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}