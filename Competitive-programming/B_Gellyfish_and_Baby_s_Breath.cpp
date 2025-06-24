#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
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

int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=(res%mod*a%mod)%mod;
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
void jarvis()
{
    int n;
    cin>>n;
    vector<int>p(n),q(n),rmq(n),rmp(n),r(n,0);
    for(auto &x:p)cin>>x;
    for(auto &x:q)cin>>x;
    for(int i=0;i<n;i++){
        rmq[i]=i;
        rmp[i]=i;
        if(i && q[i]<q[rmq[i-1]])rmq[i]=rmq[i-1];
        if(i && p[i]<p[rmp[i-1]])rmp[i]=rmp[i-1];
    }
    for(int i=0;i<n;i++){
        int pmp=rmp[i];
        int pmq=rmq[i];
        if(p[pmp]==q[pmq]){
            r[i]=(binpow(2,p[pmp])%mod+binpow(2,max(p[i-pmq],q[i-pmp]))%mod)%mod;
        }
        else if(p[pmp]>q[pmq]){
            r[i]=(binpow(2,p[pmp])%mod+binpow(2,q[i-pmp])%mod)%mod;
        }
        else{
            r[i]=(binpow(2,q[pmq])%mod+binpow(2,p[i-pmq])%mod)%mod;
        }
    }
    for(auto x:r)cout<<x<<" ";
    cout<<endl;
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