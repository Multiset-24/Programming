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

struct edge{
    int l, r, idx;
    edge() : l(0), r(0), idx(0) {}
    edge(int l, int r, int idx) {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
};
class sgt{
    public:
        vector<int>a;
        vector<int>t;
    sgt(int n){
        a.assign(n,0);
        t.assign(4*n+1,0);
    }
    void updt(int root,int l,int r,int pos,int v){
        if(pos<l || pos>r)return;
        if(l==r){
            a[l]=v;
            t[root]=v;
            return;
        }
        int mid=(l+r)/2;
        updt(2*root+1,l,mid,pos,v);
        updt(2*root+2,mid+1,r,pos,v);
        t[root]=t[2*root+1]+t[2*root+2];
    }
    int rngq(int root,int l,int r,int lq,int rq){
        if(rq<l || lq>r)return 0;
        else if(l>=lq && r<=rq)return t[root];
        int mid=(l+r)/2;
        return rngq(2*root+1,l,mid,lq,rq)+rngq(2*root+2,mid+1,r,lq,rq);
    }
    int pq(int pos){
        return a[pos];
    }
};
void jarvis()
{
    int n,m;
    cin>>n;
    vector<edge>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].idx=i;
    }
    sort(a.begin(),a.end(),[&](edge e1,edge e2){
        if(e1.r==e2.r)return e1.l>e2.l;
        else return e1.r<e2.r;
    });
    map<int,int>mp;
    vector<int>tmp;
    for(int i=0;i<n;i++){
        tmp.push_back(a[i].l);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i=0;i<tmp.size();i++){
        mp[tmp[i]]=i;
    }
    m=tmp.size();
    sgt s1(m);
    vector<int>andar(n,0);
    for(int i=0;i<n;i++){
        int pos=mp[a[i].l];
        andar[a[i].idx]=s1.rngq(0,0,m-1,pos,m-1);
        int x=s1.pq(pos);
        s1.updt(0,0,m-1,pos,x+1);
    }
    for(auto it:andar)cout<<it<<" ";
    cout<<endl;

    sort(a.begin(),a.end(),[&](edge e1,edge e2){
        if(e1.l==e2.l)return e1.r>e2.r;
        else return e1.l<e2.l;
    });
    map<int,int>mp2;
    vector<int>tmp2;
    for(int i=0;i<n;i++){
        tmp2.push_back(a[i].r);
    }
    sort(tmp2.begin(),tmp2.end());
    tmp2.erase(unique(tmp2.begin(),tmp2.end()),tmp2.end());
    for(int i=0;i<tmp2.size();i++){
        mp2[tmp2[i]]=i;
    }
    m=tmp2.size();
    sgt s2(m);
    vector<int>bahar(n,0);
    for(int i=0;i<n;i++){
        int pos=mp2[a[i].r];
        bahar[a[i].idx]=s2.rngq(0,0,m-1,pos,m-1);
        int x=s2.pq(pos);
        s2.updt(0,0,m-1,pos,x+1);
    }
    for(auto it:bahar)cout<<it<<" ";
    cout<<endl;
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