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

typedef pair<int,int> state;

vector<vector<state>>g;
vector<int>vis;
int n,m;
int global_cost=-1e9;

void dfs(int u,int cost){
    global_cost=max(global_cost,cost);
    vis[u]=1;
    for(auto it:g[u]){
        if(!vis[it.first]){
            dfs(it.first,cost+it.second);
        }
    }
    vis[u]=0;
}
void jarvis()
{
    cin>>n>>m;
    
    g.assign(n+1,vector<state>());
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
   
    for(int i=1;i<=n;i++){
        dfs(i,0);
    }

    cout<<global_cost<<endl;
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