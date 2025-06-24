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
        vector<int>arr;
        vector<int>tree;
        vector<int>cnt;
    public:
        segment_tree(vector<int>&num){
            arr=num;
            tree.resize(4*(int)num.size()+1,0);
            cnt.resize(4*(int)num.size()+1,0);

        }

        void build(int root,int l,int r){
            if(l==r){
                tree[root]=arr[l];
                cnt[root]=1;
                return;
            }

            int mid=l+(r-l)/2;

            build(2*root+1,l,mid);
            build(2*root+2,mid+1,r);

            if(tree[2*root+1]<tree[2*root+2]){
                tree[root]=tree[2*root+1];
                cnt[root]=cnt[2*root+1];
            }
            else if(tree[2*root+1]>tree[2*root+2]){
                tree[root]=tree[2*root+2];
                cnt[root]=cnt[2*root+2];
            }
            else{
                tree[root]=tree[2*root+1];
                cnt[root]+=(cnt[2*root+1]+cnt[2*root+2]);
            }

            return ;
        }

        void update(int root,int l,int r,int pos,int v){
            if(pos<l || pos>r)return ;

            if(l==r){
                tree[root]=v;
                cnt[root]=1;
                arr[l]=v;
                return;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,v);
            update(2*root+2,mid+1,r,pos,v);

            if(tree[2*root+1]<tree[2*root+2]){
                tree[root]=tree[2*root+1];
                cnt[root]=cnt[2*root+1];
            }
            else if(tree[2*root+1]>tree[2*root+2]){
                tree[root]=tree[2*root+2];
                cnt[root]=cnt[2*root+2];
            }
            else{
                tree[root]=tree[2*root+1];
                // cout<<"update-> "<<root<<" "<<tree[root]<<" "<<l<<" "<<r<<" "<<v<<" "<<cnt[2*root+1]<<" "<<cnt[2*root+2]<<" next\n ";
                cnt[root]=(cnt[2*root+1]+cnt[2*root+2]);
            }

            return;
        }

        pair<int,int> query_min(int root,int l,int r,int lq,int rq){
            if(lq>r || l>rq){
                return {1e9,-1};
            }

            if(lq<=l && r<=rq){
                // cout<<root<<" "<<tree[root]<<" "<<cnt[root]<<" "<<l<<" "<<r<<" ans-> ";
                return {tree[root],cnt[root]};
            }

            int mid=l+(r-l)/2;

            auto left_min=query_min(2*root+1,l,mid,lq,rq),right_min=query_min(2*root+2,mid+1,r,lq,rq);

            if(left_min.first<right_min.first){
                return left_min;
            }
            else if(left_min.first>right_min.first){
                return right_min;
            }
            else{
                return {left_min.first,left_min.second+right_min.second};
            }
            
            return {-1,-1};
        }

        void print(){
            for(int i=0;i<=4*arr.size();i++){
                cout<<tree[i]<<" ";
            }
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
    sgt.build(0,0,n-1);

    while(q--){
        int t;
        cin>>t;

        if(t==1){
            int k,u;
            cin>>k>>u;
            k--;
            sgt.update(0,0,n-1,k,u);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;    
            auto ans=sgt.query_min(0,0,n-1,l,r);
            cout<<ans.first<<endl;
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