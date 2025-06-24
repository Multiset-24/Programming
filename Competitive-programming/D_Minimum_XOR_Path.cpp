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
const int inf=(1LL<<61);
typedef pair<int,int> state;
vector<vector<state>>g;
vector<int>vis;
vector<int>path;
int ans=inf;
int n,m;

void dfs(int u){
    if(u==n){
        int t=0;
        for(auto it:path)t^=it;
        ans=min(ans,t);
        vis[n]=0;
        return ;
    }

    for(auto it:g[u]){
        if(!vis[it.first]){
            path.push_back(it.second);
            vis[it.first]=1;
            dfs(it.first);
            path.pop_back();
            vis[it.first]=0;
        }
    }
}

void jarvis()
{
    cin>>n>>m;

    g.assign(n+1,vector<state>());
    vis.assign(n+1,0);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vis[1]=1;
    dfs(1);

    cout<<ans<<endl;
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