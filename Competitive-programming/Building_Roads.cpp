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
vector<bool>vis;

void bfs(int node){
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        vis[curr]=true;
        for(auto v:g[curr]){
            if(!vis[v]){
                q.push(v);
            }
        }
    }
}
void jarvis()
{
    cin>>n>>m;

    g.resize(n+1);
    vis.resize(n+1,0);

    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>roads;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
            cnt++;
            roads.push_back(i);
        }
    }

    cout<<cnt-1<<endl;
    for(int i=1;i<cnt;i++){
        cout<<roads[0]<<" "<<roads[i]<<endl;
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
