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
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        xs[i] = a[i].first;
        ys[i] = a[i].second;
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int x0 = xs[0], x1 = xs[1];
    int xn1 = xs[n-1], xn2 = xs[n-2];
    int y0 = ys[0], y1 = ys[1];
    int yn1 = ys[n-1], yn2 = ys[n-2];
    int w0 = xn1 - x0 + 1;
    int h0 = yn1 - y0 + 1;
    int best = w0 * h0;
    for (int i = 0; i < n; i++) {
        int xi = a[i].first;
        int yi = a[i].second;
        int nx0 = (xi == x0 ? x1 : x0);
        int nx1 = (xi == xn1 ? xn2 : xn1);
        int ny0 = (yi == y0 ? y1 : y0);
        int ny1 = (yi == yn1 ? yn2 : yn1);
        int w = nx1 - nx0 + 1;
        int h = ny1 - ny0 + 1;
        int area = w * h;
        if (area < n) {
            int a1 = (w + 1) * h;
            int a2 = w * (h + 1);
            area = min(a1, a2);
        }
        best = min(best, area);
    }
    cout << best << endl;
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