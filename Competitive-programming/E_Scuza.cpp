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

void jarvis()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),l(q),pmx(n),psm(n);
    for(auto &it:a)cin>>it;
    for(auto &it:l)cin>>it;
    for(int i=0;i<n;i++){
        pmx[i]=a[i];
        psm[i]=a[i];
        if(i){
            pmx[i]=max(pmx[i-1],pmx[i]);
            psm[i]+=psm[i-1];
        }
    }
    for(int i=0;i<q;i++){
        int idx=upper_bound(pmx.begin(),pmx.end(),l[i])-pmx.begin();
        cout<<(idx==0?0:psm[idx-1])<<" \n"[i==q-1];
    }
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