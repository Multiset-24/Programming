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
    vector<vector<int>> a(n, vector<int>(n, 0));
    pair<int,int> cur = {(n-1)/2, (n-1)/2};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dir = 0;        
    int stp = 1;       
    int val = 0;         
    a[cur.first][cur.second] = val++;
    while (val < n * n) {
        for (int l = 0; l < 2; ++l) {
            for (int s = 0; s < stp; ++s) {
                if (val >= n * n) break;
                cur.first += dx[dir];
                cur.second += dy[dir];
                if (cur.first >= 0 && cur.first < n && cur.second >= 0 && cur.second < n) {
                    a[cur.first][cur.second] = val++;
                }
            }
            dir = (dir + 1) % 4; 
        }
        stp++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
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