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

struct node{
    int lazy=0;
    node(int a):lazy(a){}
};
class segmentTree{
    private:
        vector<int>arr;
        vector<node>tree;
    public:
        segmentTree(vector<int>&arr){
            this->arr=arr;
            node init(0);
            tree.assign(4*arr.size()+1,init);
        }

        void update(int root,int l,int r,int lq,int rq,int v){
            if(l>rq || r<lq) return ;

            if(l>=lq && r<=rq){
                tree[root].lazy+=v;
                return ;
            }

            int mid=l+(r-l)/2;

            update(2*root+1,l,mid,lq,rq,v);
            update(2*root+2,mid+1,r,lq,rq,v);
        }

        int get_query(int root,int l,int r,int i){
            if(i<l || i>r)return 0;

            if(l==r)return tree[root].lazy;

            int mid=l+(r-l)/2;

            return tree[root].lazy+get_query(2*root+1,l,mid,i)+get_query(2*root+2,mid+1,r,i);
        }
};

void jarvis()
{
    int n,m;
    cin>>n>>m;

    vector<int>num(n,0);

    segmentTree sgt(num);

    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,v;
            cin>>l>>r>>v;

            sgt.update(0,0,n-1,l,r-1,v);
        }
        else{
            int i;
            cin>>i;

            cout<<num[i]+sgt.get_query(0,0,n-1,i)<<endl;
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