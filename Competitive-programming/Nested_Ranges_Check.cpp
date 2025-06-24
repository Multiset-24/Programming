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
    int l,r,idx;
    edge(int l,int r,int idx){
        this->l=l;
        this->r=r;
        this->idx=idx;
    }
};
void jarvis()
{
    int n;
    cin>>n;
    vector<edge>a;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a.push_back(edge(l,r,i));
    }
    vector<bool>andar(n,0),bahar(n,0);
    sort(a.begin(),a.end(),[&](edge p,edge q){
        return (p.r==q.r?(p.l>q.l):(p.r<q.r));
    });
    multiset<int>ms;
    for(int i=0;i<n;i++){
        auto it=ms.lower_bound(a[i].l);
        if(it!=ms.end())andar[a[i].idx]=1;
        else andar[a[i].idx]=0;
        ms.insert(a[i].l);
    }
    for(auto it:andar)cout<<it<<" ";
    cout<<endl;
    sort(a.begin(),a.end(),[&](edge p,edge q){
        return (p.l==q.l?p.r>q.r:p.l<q.l);
    });
    ms.clear();
    for(int i=0;i<n;i++){
        auto it=ms.lower_bound(a[i].r);
        if(it!=ms.end())bahar[a[i].idx]=1;
        else bahar[a[i].idx]=0;
        ms.insert(a[i].r);
    }
    for(auto it:bahar)cout<<it<<" "; 
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