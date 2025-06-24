#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

bool check(int mid, int c[], int t[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int x = c[i];

        auto it = lower_bound(t, t + m, x - mid);

        if (it == t + m)
        {
           return false;
        }
        if(*it>x+mid)return false;
    }

    return true;
}

void jarvis()
{
    int n, m;
    cin >> n >> m;

    int c[n], t[m];

    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];

    int hi = c[n - 1] - c[0];
    int lo = 0;

    int ans = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (check(mid, c, t, n, m))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

// void jarvis()
// {
//     int n,m;
//     cin>>n>>m;

//     int c[n],t[m];

//     for(int i=0;i<n;i++)cin>>c[i];
//     for(int i=0;i<m;i++)cin>>t[i];

//     int ans=0;

//     for(int i=0;i<n;i++){
//         int x=c[i];

//         auto it=lower_bound(t,t+m,x);

//         int d=INT_MAX;

//         if(it!=t+m){
//             d=*it-x;
//         }

//         if(it!=t){
//             it--;
//             d=min(d,x-*it);
//         }

//         ans=max(ans,d);
//     }

//     cout<<ans<<endl;
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}