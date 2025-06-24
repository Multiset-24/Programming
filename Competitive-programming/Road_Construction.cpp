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

class dsu{
    public:
        vector<int>p;
        vector<int>rbs;
        int cn;
        int mcs;
        dsu(int n){
            cn=n;
            mcs=1;
            p.assign(n+1,0);
            rbs.assign(n+1,1);
            for(int i=0;i<=n;i++)p[i]=i;
        }
        int find(int x){
            return p[x]=(p[x]==x?x:find(p[x]));
        }
        void unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a!=b){
                if(rbs[a]<rbs[b])swap(a,b);
                p[b]=a;
                rbs[a]+=rbs[b];
                cn--;
                mcs=max(mcs,rbs[a]);
            }
        }
};
void jarvis()
{
    int n,m;
    cin>>n>>m;
    dsu d1(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        d1.unite(u,v);
        cout<<d1.cn<<" "<<d1.mcs<<endl;
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