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


const int MAXV = 1000000;
vector<int> spf;

void sieve() {
    spf.assign(MAXV+1, 0);
    for (int i = 2; i <= MAXV; i++) {
        if (!spf[i]) {
            for (int j = i; j <= MAXV; j += i) {
                if (!spf[j]) spf[j] = i;
            }
        }
    }
}
int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
void jarvis()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    if (x > y) {
        cout << -1 << endl;
        return;
    }
    map<int,int> dist;
    dist[y] = 0;
    queue<int> q;
    q.push(y);
    int answer = -1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        int d = dist[v];
        int maxA = min((int)k, (int)(floor(log2(v))));
        for (int a = 2; a <= maxA; a++) {
            int r = binpow(v, a) + 0.5;
            if (r > 1) {
                while (1LL*binpow(r, a) < v) r++;
                while (1LL*binpow(r, a) > v) r--;
                if (r > 1 &&binpow(r, a) == v) {
                    if (r >= x && !dist.count(r)) {
                        dist[r] = d + 1;
                        if (r == x) { answer = d+1; break; }
                        q.push(r);
                    }
                }
            }
        }
        if (answer != -1) break;
        vector<pair<int,int>> fac;
        int tmp = v;
        while (tmp > 1) {
            int p = spf[tmp];
            int cnt = 0;
            while (tmp % p == 0) {
                tmp /= p;
                cnt++;
            }
            fac.emplace_back(p, cnt);
        }
        // generate divisors recursively
        vector<int> divs = {1};
        for (auto &pr : fac) {
            int p = pr.first, c = pr.second;
            int sz = divs.size();
            int mul = 1;
            for (int e = 1; e <= c; e++) {
                mul *= p;
                for (int i = 0; i < sz; i++) {
                    divs.push_back(divs[i] * mul);
                }
            }
        }
        for (int a : divs) {
            if (a >= 2 && a <= k) {
                int u = v / a;
                if (u >= x && !dist.count(u)) {
                    dist[u] = d + 1;
                    if (u == x) { answer = d+1; break; }
                    q.push(u);
                }
            }
        }
        if (answer != -1) break;
    }
    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}