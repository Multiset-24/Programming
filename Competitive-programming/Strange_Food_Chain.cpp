#include <bits/stdc++.h>
using namespace std;

//advanced weighted dsu

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

class weighted_dsu{
    public:
        vector<state>par;
        vector<int>rank_by_size;
        int n;
        
        weighted_dsu(int n){
            this->n=n;
            par.assign(n+1,{0,0});
            rank_by_size.assign(n+1,1);
            for(int i=1;i<=n;i++)par[i]={i,0};
        }

        state find(int u){
            if(par[u].first!=u){
                state temp=find(par[u].first);
                temp.second+=par[u].second;
                return par[u]=temp;
            }
            else{
                return par[u];
            }
        }

        void unite(int x,int y,int w){
            state x1=find(x);
            state x2=find(y);
            int wt=x1.second-x2.second+w;
            if(x1.first!=x2.first){
                if(rank_by_size[x1.first]<rank_by_size[x2.first]){
                    swap(x1,x2);
                    wt=-wt;//since while calc weight we assumed edge to be from x1-x2 and if edge is between x2-x1 then weight should be reversed
                }
                par[x2.first]={x1.first,wt};
                rank_by_size[x1.first]+=rank_by_size[x2.first];
                n--;
            }
        }
};
void jarvis()
{
    int n,q;
    cin>>n>>q;

    int false_queries=0;

    weighted_dsu wd(n);

    while(q--){
        int t,u,v;
        cin>>t>>u>>v;

        if(u>n || v>n || (t==2 && u==v)){
            false_queries++;
            continue;
        }
        state pu=wd.find(u),pv=wd.find(v);
        int edge_weight=pu.second-pv.second;

        if(t==1){
            if(edge_weight!=0){
                false_queries++;
                continue;
            }
            wd.unite(u,v,0);
        }
        else{
            if(edge_weight==-1){
                false_queries++;
                continue;
            }
            else wd.unite(u,v,1);
        }
    }

    cout<<false_queries<<endl;
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