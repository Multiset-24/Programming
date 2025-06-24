#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

int n,k;
vector<int>h;
int dp[100005];

int frog_pos(int level){
    if(level<=1)return 0;

    if(dp[level]!=-1) return dp[level];

    int ans=INT_MAX;

    for(int i=1;i<=k;i++){
        if(level-i>=1)ans=min(ans,abs(h[level]-h[level-i])+frog_pos(level-i));
    }

    return dp[level]=ans;
}

void jarvis()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    h.assign(n+1,0);

    for(int i=1;i<=n;i++)cin>>h[i];

    cout<<frog_pos(n)<<endl;
}

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