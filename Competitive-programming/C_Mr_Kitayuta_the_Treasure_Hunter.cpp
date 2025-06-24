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

int n,d;
int gems[30001];

int dp[30001][1005];

int dfs(int i,int jump){
    if(i<0 || i>30001 || jump==0)return 0;

    int offset=jump-(d-250);
     if (offset < 0 || offset > 2 * 250) {
        return 0; 
    }


    if (dp[i][offset] != -1) {
        return dp[i][offset];
    }

    return dp[i][offset]=gems[i]+max({dfs(i+jump-1,jump-1),dfs(i+jump,jump),dfs(i+jump+1,jump+1)});

}

void jarvis()
{
    cin>>n>>d;

    memset(gems,0,sizeof(gems));
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        gems[x]+=1;
    }

    cout<<dfs(d,d)<<endl;
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