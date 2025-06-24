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

int n, d;
int gems[30005];
const int D = 250;
const int N = 30001;
int dp[30005][2*D+5];
int dfs(int i,int j){
    int sj=j-d+D;
    if (i >=N || j<=0)return 0;
    if(dp[i][sj]!=-1)return dp[i][sj];
    int ans=0;
    for(int l=j-1;l<=j+1;l++)ans=max(ans,gems[i]+dfs(i+l,l));
    return dp[i][sj]=ans;
}
void jarvis()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        gems[x]++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(d,d)<<endl;
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