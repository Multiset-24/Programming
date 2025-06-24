#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

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
        vector<long long> a(n);

        long long sum_wealth = 0;
        long long max_wealth = 0;

       
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum_wealth += a[i];
            max_wealth = max(max_wealth, a[i]);
        }

       sort(a.begin(),a.end());
        if (n == 1 || n==2) {
            cout << -1 << endl;
            return;
        }

    
        double avg_wealth = (double)(sum_wealth) / n;
        double half_avg = avg_wealth / 2.0;

        int unhappy_count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < half_avg) {
                unhappy_count++;
            }
        }

      
        if (unhappy_count > n / 2) {
            cout << 0 << endl;
            return;
        }

       
        long long target_sum = 2*n*a[(n)/2]-sum_wealth;
        long long min_x = target_sum+1;
        
    
       
        cout << max(min_x, 0LL) << endl;
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