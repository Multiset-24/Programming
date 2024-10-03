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
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q;
    cin >> q;

    while (q--)
    {
        int n, f, k;

        cin >> n >> f >> k;

        vector<int> a(n + 1, 0);

        int fv;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == f)
            {
                fv = a[i];
            }
        }

        int Ng = 0;
        int Nd = 0;
        int Ns = 0;

        for (auto it : a)
        {
            if (it > fv)
            {
                Ng++;
            }
            else if (it ==fv)
            {
                Nd++;
            }
            else
            {
                Ns++;
            }
        }

        if (k <= Ng)
        {
            cout << "NO" << endl;
        }
        else if (k > Ng)
        {
            if (Nd>k-Ng)
            {
                cout << "MAYBE" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}