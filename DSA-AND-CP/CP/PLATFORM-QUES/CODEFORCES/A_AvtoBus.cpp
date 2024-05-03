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

    int q;
    read(q);

    while (q--)
    {
        int n;
        read(n);

        if (n % 2 != 0 || n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int minimum = 0;
            int maximum = 0;
            n = n / 2;
            maximum = n / 2;
            if (n % 3 == 1 || n % 3 == 2)
            {
                minimum = n / 3+1;
            }
            else
            {
                minimum = n / 3;
            }

            cout << minimum << " " << maximum << endl;
        }
    }
    return 0;
}