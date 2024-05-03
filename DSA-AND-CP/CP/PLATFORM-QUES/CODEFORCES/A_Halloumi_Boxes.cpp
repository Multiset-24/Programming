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
    int t;
    read(t);

    while (t--)
    {
        int n, rl;
        read(n, rl); // n is the number of boxes and rl is the maximum length of the subarray that can be reversed;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            read(v[i]);
        }
        if (rl == 1)
        {
            bool flag = false;
            for (int i = 1; i < n; i++)
            {
                if (v[i] < v[i - 1])
                {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                    
                }
            }
            if(flag==false)cout << "YES" << endl;
            continue;
        }
        else cout<<"YES"<<endl;
        
    }
    return 0;
}