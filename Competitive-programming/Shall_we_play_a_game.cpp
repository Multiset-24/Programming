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
        if(b&1){
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}

void jarvis()
{
    int n;
    cin>>n;

    int ans=0;
    
    if(n&1){
        ans=binpow(2,n-1);
    }
    else{
        ans=(binpow(2,n-1)%mod+binpow(2,n-2)%mod)%mod;
    }

    cout<<ans<<endl;
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