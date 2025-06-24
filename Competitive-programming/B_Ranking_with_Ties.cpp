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
    vector<int> num(n, 0);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    int r = 1;
    map<int, set<int>> mp;

    for (int i = 0; i < n; i++) {
        mp[num[i]].insert(i);
    }

    vector<int> rank(n, 0);

    while (!mp.empty()) {
        auto it = mp.rbegin();
        int currentKey = it->first;
        int count = it->second.size();

        for (auto index : it->second)
            rank[index] = r;

        r += count;

        mp.erase(currentKey);
    }

    for (auto it : rank)
        cout << it << endl;
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