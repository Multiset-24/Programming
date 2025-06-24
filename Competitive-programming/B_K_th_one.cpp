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
    int sum=0;
    node (int a):sum(a){}
};

class segmentTree{
    private:
        vector<int>arr;
        vector<node>tree;
    public:
        segmentTree(vector<int>&arr){
            this->arr=arr;
            node init(0);
            tree.assign(4*(int)arr.size()+1,init);
            build(0,0,(int)arr.size()-1);
        }
        node merge(node left,node right){
            return node(left.sum+right.sum);
        }
        void build(int root,int l,int r){
            if(l==r){
                node init(arr[l]);
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
                node init(v);
                tree[root]=init;
                return;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,pos,v);
            update(2*root+2,mid+1,r,pos,v);

            tree[root]=merge(tree[2*root+1],tree[2*root+2]);
        }

        int  range_query(int root,int l,int r,int k){
            if(l==r) return l;

            int mid=l+(r-l)/2;

            if(tree[2*root+1].sum>=k){
                return range_query(2*root+1,l,mid,k);
            }
            else if(tree[2*root+2].sum>=k-tree[2*root+1].sum){
                return range_query(2*root+2,mid+1,r,k-tree[2*root+1].sum);
            }

            return -1;
        }

        void print(){
            for(int i=0;i<=4*(int)arr.size();i++){
                cout<<tree[i].sum<<" ";
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

    while(q--){
        int t,b;
        cin>>t>>b;

        if(t==1){
            num[b]=!num[b];
            sgt.update(0,0,n-1,b,num[b]);
        }
        else{
            cout<<sgt.range_query(0,0,n-1,b+1)<<endl;
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