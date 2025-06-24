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

const int maxn=2e5+10;
const int maxe=log2(maxn)+5;

vector<vector<int>>g;
vector<int>par;
int dp[maxn][25];

void dfs(int u,int p){
    par[u]=p;
    dp[u][0]=p;
    for(int l=1;l<=19;l++){
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

    memset(dp,-1,sizeof(dp));
    g.assign(n+1,vector<int>());
    par.assign(n+1,0);

    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        g[u].push_back(i);
        g[i].push_back(u);
    }

    dfs(1,-1);

    while(q--){
        int x,k;
        cin>>x>>k;

        for(int i=0;i<maxe;i++){
            if(k&(1LL<<i)){
                x=dp[x][i];
                if(x==-1)break;
            }
        }

        cout<<x<<endl;
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