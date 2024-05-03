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
    int a, b;
    read(a, b);

    int cnt = 0;
    
    u_mp<int,int>m;
    u_mp<int,int>n;
    for(int i=1;i<=a;i++){
        int x=i%5;
        m[x]++;
    }
    for(int i=1;i<=b;i++){
        int x=i%5;
        n[x]++;
    }
    for(auto i:m){
        cnt+=n[(5-i.first)%5]*i.second;
    }

    cout << cnt << endl;
    return 0;
}