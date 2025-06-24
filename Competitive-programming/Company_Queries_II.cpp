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

vector<vector<int>>g;
vector<int>depth;
vector<int>par;
const int maxn=2e5+5;
const int maxe=log2(maxn)+5;

int dp[maxn][maxe];

void dfs(int u,int p,int d){
    depth[u]=d;
    par[u]=d;
    dp[u][0]=p;
    for(int l=1;l<maxe;l++){
        if(dp[u][l-1]!=-1)dp[u][l]=dp[dp[u][l-1]][l-1];
    }
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
}


void jarvis()
{
    int n,q;
    cin>>n>>q;

    g.assign(n+1,vector<int>());
    depth.assign(n+1,0);
    par.assign(n+1,0);
    memset(dp,-1,sizeof(dp));


    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}