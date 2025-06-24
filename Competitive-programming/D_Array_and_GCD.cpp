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


const int MAXK = 4e5+10;
const int l = 6e6+10;
vector<int> primes;
vector<int> P;
void f() {
    vector<bool> is_prime(l+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= l && (int)primes.size() < MAXK; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        if (1LL * i * i <= l) {
            for (int j = i * i; j <= l; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void jarvis() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    vector<int> A(n+1, 0);
    for (int i = 1; i <= n; i++) {
        A[i] = A[i-1] + a[i-1];
    }
    int k_max = 0;
    for (int k = 1; k <= n; k++) {
        if (A[k] >= P[k]) k_max = k;
        else break;
    }

    cout << (n - k_max) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f();
    P.assign(MAXK+1,0);
    P[0] = 0;
    for (int i = 1; i < MAXK; i++) P[i] = P[i-1] + primes[i-1];
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
