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
    read(q);

    while (q--)
    {
        string s;
        read(s);
        int n = s.size();

        // 2 pointer approach

        int i = 0;
        int j = 0;

        for (int k = 0; k < n; k++)
        {
            if (s[k] == 'a')
            {
                i = k - 1;
                j = k + 1;
                break;
            }
        }

        int answered = false;
        u_mp<char, int> mp;
        for (auto c : s)
        {
            mp[c]++;
            if (mp[c] >= 2)
            {
                cout << "NO" << endl;
                answered = true;
                break;
            }
        }
        int steps = 1;
        while (steps <= n && !answered)
        {
            if ((j < n && i >= 0) && (s[i] == s[j] || s[i] > 'a' + n || s[j] > 'a' + n))
            {
                cout << "NO" << endl;
                answered = true;
                break;
            }
            if ((i >= 0 && s[i] == 'a' + steps) || (j < n && s[j] == 'a' + steps))
            {
                if(s[i] == 'a' + steps){
                    i--;
                }
                else{
                    j++;
                }
            }
            else
            {
                cout << "NO" << endl;
                answered = true;
                break;
            }
            steps++;
        }
        if (!answered)
        {
            cout << "YES" << endl;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}