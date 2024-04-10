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

    int n;
    read(n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        int x;
        read(x);

        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int sum = 0;
    if (even.size() >= 2 && odd.size() >= 2)
    {
        cout<<max(even[even.size()-1] + even[even.size()-2], odd[odd.size()-1] + odd[odd.size()-2])<<endl;
    }
    else if (even.size() >= 2)
    {
       cout<<even[even.size()-1] + even[even.size()-2]<<endl;
    }
    else if (odd.size() >= 2)
    {
        cout<<odd[odd.size()-1] + odd[odd.size()-2]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}