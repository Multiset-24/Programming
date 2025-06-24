#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    int n,m;
    cin>>n>>m;
 
    // dijkstra from n with negative and inverted edge
 
    vector<int> adj[n+1], par(n+1,-1), dist(n+1,1e15),vis(n+1,0);
    bool flag = 0;
    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,n});
    dist[n] = 0;
 
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
    
        if(vis[u])continue;
        vis[u]=1;
        for(auto v: adj[u]){
            if(dist[v] > dist[u] - 1){
                dist[v] = dist[u] - 1;
                par[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
 
    if(dist[1] == 1e15){
        cout<<"IMPOSSIBLE";
        return 0;
    }
 
    int curr = 1;
    cout<<(1-1*dist[1])<<"\n"<<curr<<" ";
    while(par[curr] != n){
        curr = par[curr];
        cout<<curr<<" ";
    }
    cout<<n;
 
    return 0;
}