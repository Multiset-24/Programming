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

int n,m;
vector<vector<char>>st;
const int maxm=1e6;
int dp[11][maxm];

int dfs(int i,int num){
    if(num==((1LL<<m)-1)) return 0;
    if(i==n)return 1e9;

    if(dp[i][num]!=-1)return dp[i][num];

    int x=0;
    for(int j=0;j<m;j++){
        if(st[i][j]=='o'){
            x|=(1LL<<(m-j-1));
        }
    }

    return dp[i][num]=min(1+dfs(i+1,num|x),dfs(i+1,num));
}

void jarvis()
{
    cin>>n>>m;

    st.assign(n+1,vector<char>(m,'o'));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>st[i][j];
        }
    }

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