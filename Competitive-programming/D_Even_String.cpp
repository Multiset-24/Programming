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
const int maxm=5e5+10;
int occ[27];
int fact[maxm];
int invfact[maxm];

int binpow(int a,int b){
    int res=1;
    
    while(b){
        if(b&1){
            res=(res%mod*a%mod)%mod%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
void factorial(){
    fact[0]=1;
    for(int i=1;i<maxm;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    invfact[maxm-1]=binpow(fact[maxm-1],mod-2);

    for(int i=maxm-2;i>=0;i--){
        invfact[i]=(invfact[i+1]*(i+1))%mod;
    }
}

void jarvis()
{   
    int sm = 0;
    for(int i = 0; i < 26; i++){
        cin >> occ[i];
        sm += occ[i];
    }
    
    int odd_places = sm / 2;
    vector<vector<int>>dp(27,vector<int>(odd_places+10,0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= 26; i++){
        for (int o = 0; o <= odd_places; o++){
            dp[i][o] = dp[i-1][o];
            if(o - occ[i-1] >= 0){
                dp[i][o] = (dp[i][o] + (occ[i-1]==0?0:dp[i-1][o - occ[i-1]])) % mod;
            }
        }
    }
    
    int y = dp[26][odd_places];
    int even_places = (sm + 1) / 2;
    
    int num = (y * fact[odd_places]) % mod;
    num = (num * fact[even_places]) % mod;
    
    int den = 1;
    for (int i = 0; i < 26; i++){
        den = (den * invfact[occ[i]]) % mod;
    }
    
    int ans = (num * den) % mod;
    cout << ans << endl; 
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}