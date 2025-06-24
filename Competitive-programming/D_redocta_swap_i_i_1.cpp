#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &p : m) cout << "{" << p.first << ": " << p.second << "} "; cout << "}" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#endif
#define endl '\n'

void jarvis() {
    string S;
    cin >> S;
    const string target = "atcoder";

    queue<string> q;
    map<string, int> dist;
    q.push(S);
    dist[S] = 0;

    while (!q.empty()) {
        string cur = q.front(); q.pop();
        int d = dist[cur];
        if (cur == target) {
            cout << d << endl;
            return;
        }
        for (int i = 0; i + 1 < 7; i++) {
            string nxt = cur;
            swap(nxt[i], nxt[i+1]);
            if (!dist.count(nxt)) {
                dist[nxt] = d + 1;
                q.push(nxt);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)jarvis();
    return 0;
}
