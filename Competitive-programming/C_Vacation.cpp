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

int days;

vector<vector<int>>g;
int dp[100050][4];

int vacation_cost(int level,int use){
    if(level==0)return 0;

    if(dp[level][use]!=-1)return dp[level][use];

    int ans=INT_MIN;

    for(int i=0;i<3;i++){
        if(i!=use){
            ans=max(ans,g[level][use]+vacation_cost(level-1,i));
        }
    }

    return dp[level][use]=ans;
}
void jarvis()
{
    cin>>days;

    memset(dp,-1,sizeof(dp));

    g.assign(days+1,vector<int>(3,0));

    for(int i=1;i<=days;i++){
        cin>>g[i][0]>>g[i][1]>>g[i][2];
    }

    int max_cost=max({vacation_cost(days,0),vacation_cost(days,1),vacation_cost(days,2)});

    cout<<max_cost<<endl;
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