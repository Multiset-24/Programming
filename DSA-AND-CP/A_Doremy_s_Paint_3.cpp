#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)          \
    vector<int> v(n);           \
    for (int i = 0; i < n; ++i) \
        cin >> v[i];
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
// This is policy based data structure for ordered sets which gives additional features like find_by_order(x) and order_of_key(x);

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

    u_mp<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    if (mp.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        for (auto it : mp)
        {
            if (it.second == n){
                cout << "YES" << endl;
                return;
            }
            if (it.second != n / 2 && it.second != (n + 1) / 2)
            {
                cout << "NO" << endl;
                return;
            }
        }

        cout << "YES" << endl;
    }
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

//MISTAKES THAT I AM MAKING //\

/*
1. Try to solve 2 problem above your limit
2. Always check if you have declared any variable for input taking have you taken input or not this can give bad_alloc error
3. max and min function are made for taking arguments of same type i.e max(x,y) is valid only if x and y are of same type




*/