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
vector<int>group;

bool dfs(int node,int gr){
    vis[node]=true;
    group[node]=gr;
    bool flag=true;
    for(auto v:g[node]){
        if(vis[v]){
            if(group[v]==gr)return false;
        }
        else{
            flag=flag&dfs(v,1-gr);
        }
    }
    return flag;
}
void jarvis()
{
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    vis.resize(n+1,false);
    group.resize(n+1,-1);
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool flag=dfs(i,0);
            if(flag==false){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(group[i]==0)cout<<1<<" ";
        else cout<<2<<" ";
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