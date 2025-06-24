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

void jarvis()
{
    int n;
    cin>>n;
    vector<pair<int,int>>edg(n);
    vector<int>st;st.push_back(1);
    //co-ordinate compression
    for(auto &p:edg){
        cin>>p.first>>p.second;
        st.push_back(p.first);
        st.push_back(p.second);
    }
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    map<int,int>mp;
    int N=st.size();
    for(int i=0;i<N;i++)mp[st[i]]=i;
    vector<vector<int>>g(N+1,vector<int>());
    for(int i=0;i<n;i++){
        int u=edg[i].first,v=edg[i].second;
        g[mp[u]].push_back(mp[v]);
        g[mp[v]].push_back(mp[u]);
    }
    queue<int>q;
    q.push(mp[1]);
    vector<int>dist(N+1,1e18);
    dist[mp[1]]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    int mf=1;
    for(int j=0;j<N;j++){
        if(dist[j]!=1e18)mf=max(mf,st[j]);
    }
    cout<<mf<<endl;
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