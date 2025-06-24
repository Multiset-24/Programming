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

int n;
int cnt[100005];
int dp[100005];

int dfs(int i){
    if(i==1 || i==0) return cnt[i];
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(dfs(i-1),cnt[i]*i+dfs(i-2));
}

void jarvis()
{
    cin>>n;

    int maxm=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxm=max(maxm,x);
        cnt[x]++;
    }

    cout<<dfs(maxm)<<endl;
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