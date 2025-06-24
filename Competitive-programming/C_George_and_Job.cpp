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

int dp[5005][5005];
void jarvis()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>num(n,0);
    for(auto &x:num)cin>>x;
    vector<int>pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+num[i-1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0)dp[i][j]=0;
            else dp[i][j]=-1e15;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(i-m>=0){
                dp[i][j]=max((pref[i]-pref[i-m])+dp[i-m][j-1],dp[i][j]);
            }
        }
    }
    cout<<dp[n][k]<<endl;
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