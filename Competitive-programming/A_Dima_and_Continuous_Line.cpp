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
bool segments_intersect(pair<int, int> seg1, pair<int, int> seg2) {
    int a = seg1.first, b = seg1.second;
    int c = seg2.first, d = seg2.second;
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    int overlap = min(b, d) - max(a, c);
    if (overlap > 0 && !(a >= c && b <= d) && !(c >= a && d <= b)) {
        return true; 
    }
    return false;
}
void jarvis()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &x : num) cin >> x;
    set<pair<int, int>> segments;
    for (int i = 0; i < n - 1; ++i) {
        int a = num[i], b = num[i + 1];
        pair<int, int> new_seg = {min(a, b), max(a, b)};
        for (auto seg : segments) {
            if (segments_intersect(seg, new_seg)) {
                cout << "yes" << endl;
                return;
            }
        }
        segments.insert(new_seg);
    }
    cout << "no" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
