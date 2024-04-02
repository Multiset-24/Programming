#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    read(n, m, k);

    vector<int> kth_common_divisor;
    for (int i = 1; i <= min(m, n); i++)
    {
        if (n % (i) == 0 && m % (i) == 0)
        {
            kth_common_divisor.push_back(i);

        }
    }

    
    sort(kth_common_divisor.begin(), kth_common_divisor.end());

    if (kth_common_divisor.size() >= k)
    {
        cout << kth_common_divisor[kth_common_divisor.size()-k] << endl;
    }
    return 0;
}