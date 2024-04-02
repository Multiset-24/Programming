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

    int a, b;
    read(a, b);

    int sum_a = 0;
    int sum_b = 0;
    while (a > 0)
    {
        sum_a += a % 10;
        a /= 10;
    }
    while (b > 0)
    {
        sum_b += b % 10;
        b /= 10;
    }

    cout << max(sum_a, sum_b) << endl;
    return 0;
}