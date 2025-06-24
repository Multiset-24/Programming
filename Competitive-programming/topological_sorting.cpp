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
#define prin9t_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

vector<vector<int>>g;
vector<int>vis;
vector<int>topo;
vector<int>indegree;

void topo_dfs(int node){
    vis[node]=true;

    for(auto v:g[node]){
        if(!vis[v]){
            topo_dfs(v);
        }
    }
    topo.push_back(node);
}
void jarvis()
{
    int n,m;
    cin>>n>>m;

    topo.clear();
    g.assign(n+1,vector<int>());
    vis.assign(n+1,0);
    indegree.assign(n+1,0);

    while(m--){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        indegree[v]++;
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int t=q.front();
        q.pop();
        topo.push_back(t);
        for(auto v:g[t]){
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     if(!vis[i])topo_dfs(i);
    // }

    // reverse(topo.begin(),topo.end());

    for(auto v:topo){
        cout<<v<<" ";
    }
    cout<<endl;
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
