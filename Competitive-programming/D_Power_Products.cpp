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
const int N=1e6;
int spf[N+2];
void seive(){
    for(int i=0;i<N;i++)spf[i]=i;
    for(int i=2;i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j)spf[j]=i;
            }
        }
    }
}
map<int,int> fpf(int x){
    map<int,int>mp;
    while(x>1){
        mp[spf[x]]++;
        x/=spf[x];
    }
    return mp;
}
int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
pair<int,int> rcf(int x,int k){
    int r=1,c=1;
    auto fp=fpf(x);
    for(auto it:fp){
        int rm=it.second%k;
        if(rm==0)continue;
        r*=binpow(it.first,rm);
        c*=binpow(it.first,k-rm);
    }
    return {r,c};
}
void jarvis()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    map<int,int>mp;
    int ans=0;
    for(auto x:a){
        auto p=rcf(x,k);
        ans+=mp[p.second];
        mp[p.first]++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}