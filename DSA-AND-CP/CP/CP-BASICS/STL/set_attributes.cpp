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
    set<int> s;
    int t;

    read(t);

    while (t--)
    {
        string operation;
        read(operation);
        int n;
        read(n);

        if (operation == "insert")
        {
            s.insert(n);
        }
        else if (operation == "find")
        {
            if (s.find(n) != s.end())
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
        else if (operation == "upper_bound")
        {
            auto ans = *s.upper_bound(n);
            if(s.find(ans)==s.end()){
                cout<<"-1"<<endl;
                continue;
            }
            else cout << ans << endl;
        }
        else if (operation == "lower_bound")
        {
            auto ans = *s.lower_bound(n);
            if(s.find(ans)==s.end()){
                cout<<"-1"<<endl;
                continue;
            }
           else  cout << ans << endl;
        }
    }
    return 0;
}