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

int a,b;
vector<int>dg;
int dp[20][10][3][3];
int dfs(int i,int prev,bool loose,bool nzu){
    if(i==19)return 1;
    if(dp[i][prev][loose][nzu]!=-1)return dp[i][prev][loose][nzu];
    int cnt=0;
    for(int j=0;j<=(loose?9:dg[i]);j++){
        int l=(loose||(j<dg[i]));
        int nz=(nzu||(j>0));
        if(!nz)cnt+=dfs(i+1,j+1,l,0);
        else if(j!=prev-1)cnt+=dfs(i+1,j+1,l,nz);
    }
    return dp[i][prev][loose][nzu]=cnt;
}
int Cn(int x){
    memset(dp,-1,sizeof(dp));
    dg.assign(19,0);
    for (int i = 18; i >= 0; i--) {
        dg[i] = x % 10;
        x /= 10;
    }
    return dfs(0,0,false,false);
}
void jarvis()
{
    cin>>a>>b;
    cout<<Cn(b)-Cn(a-1)<<endl;
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