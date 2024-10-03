#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n) vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i];
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

void jarvis()
{
    int x, y, z, k;
    read(x, y, z, k);
    int ans = INT_MIN;
    for (int a = 1; a <= x; a++)
    {
        for (int b = 1; b <= y; b++)
        {
            bool flag1 = false;
            bool flag2 = false;
            int c = k / (a * b);
            if (k % (a * b) == 0)
            {
                flag1 = true;
            }

            if (k / (a * b) <= z)
            {
                flag2 = true;
            }

            if (flag1 && flag2)
            {
                int count = (x - a + 1);
                count *= (y - b + 1);
                count *= (z - c + 1);

                ans = max(ans, count);
            }
        }
    }

    if (ans != INT_MIN)
        cout << ans << endl;
    else
        cout << 0 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q;
    cin >> q;
    while (q--)
    {
        jarvis();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}