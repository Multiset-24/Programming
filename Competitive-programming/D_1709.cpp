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
    vector<vector<int>> g(2, vector<int>(n));
    vector<pair<int,int>> ans;
    map<int, pair<int,int>> mp, mpo;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            mpo[g[i][j]] = {i, j};
        }
    }
    int k = 0;
    for (int num = 1; num <= 2 * n; num += 2) {
        mp[num] = {0, k++};
    }
    k = 0;
    for (int num = 2; num <= 2 * n; num += 2) {
        mp[num] = {1, k++};
    }
    auto sr = [&](int l, int r, int row) {
        while (l < r) {
            ans.push_back({row + 1, r});
            swap(g[row][r - 1], g[row][r]);
            mpo[g[row][r - 1]] = {row, r - 1};
            mpo[g[row][r]] = {row, r};
            r--;
        }
    };
    auto sl = [&](int l, int r, int row) {
        while (l < r) {
            ans.push_back({row + 1, l + 1});
            swap(g[row][l], g[row][l + 1]);
            mpo[g[row][l]] = {row, l};
            mpo[g[row][l + 1]] = {row, l + 1};
            l++;
        }
    };
    for (int x = 1; x <= 2 * n; x++) {
        auto p1= mpo[x];
        auto p2 = mp[x];
        int r=p1.first,c=p1.second,Or=p2.first,Oc=p2.second;
        if (r != Or) {
            ans.push_back({3, c + 1});
            swap(g[r][c], g[Or][c]);
            mpo[g[r][c]] = {r, c};
            mpo[g[Or][c]] = {Or, c};
            r = Or;
        }
        if (c > Oc)
            sr(Oc, c, r);
        else if (c < Oc)
            sl(c, Oc, r);
    }
    cout << ans.size() << endl;
    for (auto &p : ans) {
        cout << p.first << " " << p.second << endl;
    }
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