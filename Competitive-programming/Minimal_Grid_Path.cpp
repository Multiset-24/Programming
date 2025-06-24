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
    vector<string>g(n);
    set<char>sm;
    for(auto &x:g){
        cin>>x;
        for(auto c:x){
            sm.insert(c);
        }
    }
    if(sm.size()==1){
        for(int i=0;i<2*n-1;i++){
            cout<<g[0][0];
        }
        cout<<endl;
        return;
    }
    string ans="";
    set<pair<int,int>>q;
    q.insert({0,0});
    for(int st=0;st<2*n-1;st++){
        char bst='Z'+1;
        for(auto p:q){
            bst=min(bst,g[p.first][p.second]);
        }
        ans+=bst;
        set<pair<int,int>>nq;
        for(auto p:q){
            int r=p.first,c=p.second;
            if(g[r][c]!=bst)continue;
            if(r+1<n)nq.insert({r+1,c});
            if(c+1<n)nq.insert({r,c+1});
        }
        q=nq;
    }
    cout<<ans<<endl;
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