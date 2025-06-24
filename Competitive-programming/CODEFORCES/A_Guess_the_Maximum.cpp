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

void jarvis()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Initialize k to a very large value
    int max_k = INT_MAX;

    // Traverse through adjacent pairs
    for (int i = 0; i < n - 1; ++i)
    {
        // Find the maximum of the current pair
        int current_max = max(a[i], a[i + 1]);
        // Update max_k to be the minimum of the current maximums
        max_k = min(max_k, current_max);
    }

    // Output the maximum k for which Alice is guaranteed to win
    cout << max_k-1<< endl;
    return;
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