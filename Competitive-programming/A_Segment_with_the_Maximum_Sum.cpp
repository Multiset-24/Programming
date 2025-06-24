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

const int ninf=-1e18;

struct node{
    int msum=ninf,lmsum=ninf,rmsum=ninf,total=ninf;
    node(int a=ninf, int b=ninf, int c=ninf, int d=ninf) : msum(a), lmsum(b), rmsum(c), total(d) {}
};

class segmentTree{
    private:
        vector<int>arr;
        vector<node>tree;
    public:
        segmentTree(vector<int>&arr){
            this->arr=arr;
            node init(ninf, ninf, ninf,ninf);
            tree.assign(4*(int)arr.size()+1,init);
            build(0,0,(int)arr.size()-1);
        }
        node merge(node left,node right){

            int a=max({left.msum,right.msum,left.rmsum+right.lmsum});
            int b=max(left.lmsum,left.total+right.lmsum);
            int c=max(right.rmsum,right.total+left.rmsum);
            int d=left.total+right.total;

            return node(a,b,c,d);
        }
        void build(int root,int l,int r){
            if(l==r){
                node init(arr[l],arr[l],arr[l],arr[l]);
                tree[root]=init;
                return;
            }

            int mid=l+(r-l)/2;

            build(2*root+1,l,mid);
            build(2*root+2,mid+1,r);

            tree[root]=merge(tree[2*root+1],tree[2*root+2]);
        }
        void update(int root,int l,int r,int pos,int v){
            if(pos>r || pos<l)return;

            if(l==r){
                node init(v,v,v,v);
                tree[root]=init;
                return;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,v);
            update(2*root+2,mid+1,r,pos,v);

            tree[root]=merge(tree[2*root+1],tree[2*root+2]);
        }

        node range_query(int root,int l,int r,int lq,int rq){
            if(r<lq || l>rq)return node(ninf, ninf, ninf, ninf);

            if(l>=lq && r<=rq){
                return tree[root];
            }

            int mid=l+(r-l)/2;

            node left=range_query(2*root+1,l,mid,lq,rq);
            node right=range_query(2*root+2,mid+1,r,lq,rq);
            
            return merge(left,right);
        }

        void print(){
            for(int i=0;i<=4*arr.size();i++){
                cout<<tree[i].msum<<" ";
            }
            cout<<endl;
        }
};
void jarvis()
{
    int n,q;
    cin>>n>>q;

    vector<int>num(n,0);
    for(int i=0;i<n;i++)cin>>num[i];

    segmentTree sgt(num);
    node ans=sgt.range_query(0,0,n-1,0,n-1);
    cout<<(ans.msum<0?0:ans.msum)<<endl;
    while(q--){
        int k,c;
        cin>>k>>c;

        sgt.update(0,0,n-1,k,c);
        // sgt.print();
        ans=sgt.range_query(0,0,n-1,0,n-1);
        cout<<(ans.msum<0?0:ans.msum)<<endl;
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