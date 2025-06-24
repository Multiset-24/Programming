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
int n,m;
vector<vector<int>>g;
vector<int>dist;
const int INF=1e7;
vector<int>parent;

void bfs(int node){
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto v:g[curr]){
            if(dist[v]>dist[curr]+1){
                dist[v]=dist[curr]+1;
                parent[v]=curr;
                q.push(v);
            }
        }
    }
}

void jarvis()
{
    cin>>n>>m;

    g.resize(n+1);
    dist.resize(n+1,INF);
    parent.resize(n+1,-1);

    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist[1]=1;
    bfs(1);

    if(dist[n]==INF){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n]<<endl;
        int curr=n;
        vector<int>path;
        while(curr!=-1){
            path.push_back(curr);
            curr=parent[curr];
        }
        reverse(path.begin(),path.end());
        for(auto p:path)cout<<p<<" ";
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
