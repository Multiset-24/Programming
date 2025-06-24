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

const int inf=1e18;
void jarvis()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1,vector<int>());
    vector<int>dst(n+1,inf),ndst(n+1,0);
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int>q;
    dst[1]=0;
    ndst[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dst[v]>dst[u]+1){
                dst[v]=dst[u]+1;
                ndst[v]=ndst[u];
                q.push(v);
            }
            else if(dst[v]==dst[u]+1)ndst[v]=(ndst[v]%mod+ndst[u]%mod)%mod;
        }
    }
    cout<<ndst[n]<<endl;
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