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
vector<int>dis;
vector<int>parent;
const int INF=1e7;

// time complexity O(V+E)*log(E)
void Dijkastra(int node){
    multiset<state>ms;
    ms.insert({0,1});
    dis[1]=0;

    while(!ms.empty()){
        state curr=*ms.begin();
        ms.erase(ms.begin());

        int curr_node=curr.second;
        int curr_dis=curr.first;

        if(vis[curr_node])continue;//significantly reduces time complexity since now every node can be visited only once 
        vis[curr_node]=1;

        for(auto [v,w]:g[curr_node]){//this might give error in some machines so consider using general syntax if gives error here 
            if(d[v]>d[curr_node]+w){//relaxing edge
                d[v]=d[curr_node]+w;
                ms.insert({d[v],v});
                parent[v]=curr_node;
            }
        }
    }
}
void jarvis()
{
    int n,m;
    cin>>n>>m;

    g.assign(n+1,vector<state>());
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    parent.assign(n+1,-1);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
    }

    Dijkastra(1);

    
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