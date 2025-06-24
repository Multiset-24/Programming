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

vector<vector<int>>g;
vector<int>depth;

void dfs(int u,int p,int d){
    depth[u]=d;
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u,d+1);
        }
    }
    return;
}
void jarvis()
{
    int n;
    cin>>n;

    vector<int>am(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>am[i];
    }

    g.assign(2*n+2,vector<int>());
    depth.assign(2*n+2,0);


    for(int i=1;i<=n;i++){
        g[am[i]].push_back(2*i);
        g[am[i]].push_back(2*i+1);
    }

    dfs(1,0,0);

    for(int i=1;i<=2*n+1;i++){
        cout<<depth[i]<<endl;
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