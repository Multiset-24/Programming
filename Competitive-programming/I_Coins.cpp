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

vector<ld>probability;

ld dp[3005][3005];

ld dfs(int i,int h){
    if(i==-1){
        if(h==0)return 1.0;
        else return 0.0;
    }

    if(dp[i][h]!=-1.0)return dp[i][h];

    ld ans=0.0L;

    ans=dfs(i-1,h-1)*probability[i];
    
    ans+=dfs(i-1,h)*(1-probability[i]);

    return dp[i][h]=ans;
}

void jarvis()
{
    int n;
    cin>>n;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n+1;j++){
            dp[i][j]=-1.0;
        }
    }

    probability.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>probability[i];
    }

    ld ans=0.0L;

    for(int heads=(n/2)+1;heads<=n;heads++){
        ans+=dfs(n-1,heads);
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;
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