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
int stones[105];
int dp[1000005];

int whoWins(int x){
    if(x==0)return 0;

    if(dp[x]!=-1)return dp[x];
    
    for(int i=1;i<=n;i++){
        if(x-stones[i]>=0 && !whoWins(x-stones[i]))return dp[x]=1;
    }

    return dp[x]=0;
}

void jarvis()
{
    cin>>n>>k;

    // memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++)cin>>stones[i];

    dp[0]=0;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i-stones[j]>=0)dp[i]=dp[i]|!(dp[i-stones[j]]);
        }
    }
    if(dp[k]==1)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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