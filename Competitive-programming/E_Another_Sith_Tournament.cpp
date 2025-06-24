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

typedef long double ld;

int n;
vector<vector<ld>>probability;
ld dp[20][(1LL<<19)];

ld dfs(int last_champ,int mask){
    if(mask==0){
        if(last_champ==0)return 1.0;
        else return 0.0;
    }

    if(dp[last_champ][mask]!=-1.0)return dp[last_champ][mask];

    ld ans=-1.0;

    for(int i=0;i<n;i++){
        if((mask&(1LL<<i))==0)continue;

        int new_mask=(mask^(1LL<<i));

        ans=max(ans,(probability[last_champ][i]*dfs(last_champ,new_mask)+probability[i][last_champ]*dfs(i,new_mask)));
    }

    return dp[last_champ][mask]=ans;
}

void jarvis()
{
    cin>>n;
    probability.assign(n,vector<ld>(n,0.0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>probability[i][j];
        }
    }
    
    int initial_mask=((1LL<<(n))-1);

    ld ans=-1.0;

    for(int i=0;i<n;i++){
        int updated_mask=(initial_mask^(1LL<<i));
        ans=max(ans,dfs(i,updated_mask));
    }

    cout<<fixed<<setprecision(15)<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1;i<20;i++){
        for(int j=0;j<(1LL<<19);j++){
            dp[i][j]=-1.0;
        }
    }

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}