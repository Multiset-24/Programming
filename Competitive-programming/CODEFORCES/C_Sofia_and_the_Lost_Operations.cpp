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
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int m;
    cin >> m;

    vector<int> d(m,0);
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }

    map<int, int> freq;
    for (int i = 0; i < m; i++)
    {
        freq[d[i]]++;
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {

        if (b[i] == d[m - 1])
            flag = true;
        if (a[i] != b[i])
        {
            if (freq.find(b[i])!=freq.end())
            {
                freq[b[i]]--;
                if (freq[b[i]] == 0)
                {
                    freq.erase(b[i]);
                }
            }
            else
            {

                cout << "NO" << endl;
                return;
            }
        }
    }
    if (freq.size() > 0 && flag == false)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    cout << endl;
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