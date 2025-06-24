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
const int N=2e5;
string s;
int n;
int dp[N];
int dfs(int i){
    if(s[i]=='m' || s[i]=='w')return 0;
    if(i==n)return 1;
    if(dp[i]!=-1)return dp[i];
    if(i+1<n && s[i]==s[i+1] && (s[i]=='u' || s[i]=='n'))return dp[i]=(dfs(i+2)%mod+dfs(i+1)%mod)%mod;
    else return dp[i]=dfs(i+1)%mod;
}
void jarvis()
{
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0)<<endl;
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