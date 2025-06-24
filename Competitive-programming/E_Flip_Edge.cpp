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
int n,m,x;
vector<vector<state>>g;
vector<int>dis;
vector<int>vis;
const int inf=1e15;

void jarvis()
{
    cin>>n>>m>>x;
    g.assign(n+1,vector<state>());
    dis.assign(n+1,inf);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,1});
        g[v].push_back({u,x});
    }
    multiset<state>dq;
    dq.insert({0,1});
    dis[1]=0;
    while(!dq.empty()){
        state st=*dq.begin();
        dq.erase(st);
        int u=st.second;

        if(vis[u])continue;
        vis[u]=1;

        for(auto it:g[u]){
            int v=it.first,w=it.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                dq.insert({dis[v],v});
            }
        }
    }
    cout<<dis[n]<<endl;
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