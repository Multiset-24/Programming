#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define endl '\n'

// Debugging macros
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

// Alternative to KMP algorithm for hashing
struct hasher {
    int n, k, p;
    vector<int> powk;
    vector<int> base2k;
    vector<int> revbase2k;
    string s;

    void init(int n, int k, int p, string &s) {
        this->n = n;
        this->k = k;
        this->p = p;
        this->s = s;

        powk.assign(n + 1, 0);
        base2k.assign(n + 1, 0);
        revbase2k.assign(n + 1, 0);

        base2k[0] = 0;
        powk[0] = 1;

        for (int i = 0; i < n; i++) {
            base2k[i + 1] = ((base2k[i] % p * k % p) % p + (s[i] - 'a' + 1)) % p;
            powk[i + 1] = (powk[i] * k) % p;
        }

        revbase2k[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            revbase2k[i] = ((revbase2k[i + 1] % p * k % p) % p + (s[i] - 'a' + 1)) % p;
        }
    }

    int getHash(int l, int r) {
        return (base2k[r + 1] - (base2k[l] * powk[r - l + 1]) % p + p) % p;
    }

    int getRevHash(int l, int r) {
        return (revbase2k[l] - (revbase2k[r + 1] * powk[r - l + 1]) % p + p) % p;
    }
};

void jarvis() {
    string t, s;
    cin >> t >> s;
    int n = t.size(), m = s.size();

    hasher hasht, hashs;
    hasht.init(n, 31, 1000000009, t);
    hashs.init(m, 31, 1000000009, s);

    //# of occurrences of T in S in O(N);
    for (int l = 0; l + n - 1 < m; l++) {
        if (hashs.getHash(l, l + n - 1) == hasht.getHash(0, n - 1)) {
            cout << l << " " << l + n - 1 << endl;
        }
    }

    //# of distinct substrings in S
    hasher double_hashS;
    double_hashS.init(m, 37, 1000000007, s);
    set<pair<int, int>> us;

    for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) { // Fixed the range: r should start from l
            us.insert({hashs.getHash(l, r), double_hashS.getHash(l, r)});
        }
    }

    cout << us.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    while (q--) {
        jarvis();
    }
    return 0;
}
