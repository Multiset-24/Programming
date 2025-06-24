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

class segment_tree{
    private:
        vector<int>tree;
    public:
        segment_tree(vector<int>&arr){
            tree.assign(4*arr.size()+1,0);
            build(0,0,arr.size()-1);
        }

        void build(int root,int l,int r){
            if(l==r){
                tree[root]=0;
                return;
            }

            int mid=l+(r-l)/2;
            build(2*root+1,l,mid);
            build(2*root+2,mid+1,r);

            tree[root]=tree[2*root+1]+tree[2*root+2];
        }

        void update(int root,int l,int r,int pos,int val){
            if(pos<l || pos>r)return ;

            if(l==r){
                tree[root]+=val;
                return;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,val);
            update(2*root+2,mid+1,r,pos,val);

            tree[root]=tree[2*root+1]+tree[2*root+2];

            return ;
        }

        int get_range_sum(int root,int l,int r,int lq,int rq){
            if(l>rq || lq>r)return 0;

            if(l>=lq && r<=rq){
                return tree[root];
            }

            int mid=l+(r-l)/2;

            return get_range_sum(2*root+1,l,mid,lq,rq)+get_range_sum(2*root+2,mid+1,r,lq,rq);
        }
};

void jarvis()
{
    int n,q;
    cin>>n>>q;

    vector<int>arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    segment_tree sgt(arr);

    while(q--){
        int t;
        cin>>t;

        if(t==1){
            int l,r,v;
            cin>>l>>r>>v;
            l--,r--;
            sgt.update(0,0,n-1,l,v);
            sgt.update(0,0,n-1,r+1,-v);
        }
        else{
            int k;
            cin>>k;
            k--;
            cout<<sgt.get_range_sum(0,0,n-1,0,k)+arr[k]<<endl;
        }
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