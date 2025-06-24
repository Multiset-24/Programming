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

const int ninf=-1e9;

class segmentTree{
    private:
        vector<int>val;
        vector<int>tree;
    public:
        segmentTree(vector<int>&arr){
            val=arr;
            tree.assign(4*arr.size()+2,ninf);
            build(0,0,arr.size()-1);
        }

        void build(int root,int l,int r){
            if(l==r){
                tree[root]=val[l];
                return;
            }

            int mid=l+(r-l)/2;

            build(2*root+1,l,mid);
            build(2*root+2,mid+1,r);

            tree[root]=max(tree[2*root+1],tree[2*root+2]);
        }

        void update(int root,int l,int r,int pos,int v){
            if(pos<l || pos>r)return ;

            if(l==r){
                tree[root]=v;
                return;
            }
            
            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,v);
            update(2*root+2,mid+1,r,pos,v);

            tree[root]=max(tree[2*root+1],tree[2*root+2]);

            return;
        }

        int get_index(int root,int l,int r,int req){
            if(l==r && tree[root]>=req){
                update(0,0,val.size()-1,l,tree[root]-req);
                return l;
            }
            else if(l==r)return ninf;

            int mid=l+(r-l)/2;

            if(tree[root]<req){
                return ninf;
            }
            else if(tree[2*root+1]>=req){
                return get_index(2*root+1,l,mid,req);
            }
            else if(tree[2*root+2]>=req){
                return get_index(2*root+2,mid+1,r,req);
            }

            return ninf;
        }
};
void jarvis()
{
    int n,m;
    cin>>n>>m;

    vector<int>hotels(n,0);

    for(int i=0;i<n;i++)cin>>hotels[i];

    vector<int>requirements(m,0);

    for(int i=0;i<m;i++)cin>>requirements[i];

    segmentTree sgt(hotels);

    for(auto it:requirements){
        int ans=sgt.get_index(0,0,n-1,it);
        cout<<(ans==ninf?0:ans+1)<<endl;
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