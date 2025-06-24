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
const int N=2e5+10;
string s;
int n;
int dp[N][5];
int dfs(int i,int r){
    if(i>=n)return 0;
    if(dp[i][r]!=-1)return dp[i][r];
    if((r+(s[i]-'0'))%3==0)return dp[i][r]=1+dfs(i+1,0);
    else return dp[i][r]=max(dfs(i+1,0),dfs(i+1,(r+(s[i]-'0'))%3));    
}
void jarvis()
{
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,0)<<endl;
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