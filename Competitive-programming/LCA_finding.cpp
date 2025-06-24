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
vector<vector<int>>dp;
int n,r;
int MAXE;

void dfs(int u,int p,int d){
    depth[u]=d;
    dp[u][0]=p;

    for(int l=1;l<MAXE;l++){
        if(dp[u][l-1]!=-1)dp[u][l]=dp[dp[u][l-1]][l-1];
    }
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u,d+1);
        }
    }

    return;
}

int LCA(int u,int v){
    if(depth[u]<depth[v])swap(u,v);

    int jump=depth[u]-depth[v];

    for(int i=0;i<MAXE;i++){
        if(jump&(1LL<<i)){
            u=dp[u][i];
            if(u==-1)break;
        }
    }
    if(v==u)return u;
    
    //now both of u and v are at same level , now jump them both simultaneously till they reach at same level

    for(int i=MAXE-1;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }

    return dp[u][0];
}
void jarvis()
{
    cin>>n>>r;
    MAXE=(int)log2(n)+1;//important there might be some which will be not working on log2(n)+1 since 2^j<=n and at equility j=log2(n) not log2(n+1)
    g.assign(n+1,vector<int>());
    depth.assign(n+1,0);
    dp.assign(n+1,vector<int>(MAXE,-1));

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(r,-1,0);

    int q;
    cin>>q;

    while(q--){
        int u,v;
        cin>>u>>v;

        cout<<LCA(u,v)<<endl;
    }
    
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