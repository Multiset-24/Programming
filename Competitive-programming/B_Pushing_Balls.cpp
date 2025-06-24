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

int dp[55][55][2];

void jarvis()
{   
    int n,m;
    cin>>n>>m;
    vector<string>grid(n," ");
    for(auto &s:grid)cin>>s;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                if(grid[i][j]=='1')dp[i][j][0]=dp[i][j][1]=1;
                continue;
            }
            if(grid[i][j]=='1'){
                if(grid[i-1][j]=='1' && dp[i-1][j][0]==1)dp[i][j][0]=1;
                if(grid[i][j-1]=='1' && dp[i][j-1][1]==1)dp[i][j][1]=1;
                if(dp[i][j][0]==0 && dp[i][j][1]==0){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    return;
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