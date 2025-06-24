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

vector<int>zn;
map<pair<int,int>,int>dp;

void zn_init(){
    for(int i=1;i<=1e18;i=(4*i+1)){
        zn.push_back(i);
    }
}

int dfs(int x,int k){// this finds the number of integers in 0 to x having zebra value equals to k
    if(x==0 && k==0)return 1;
    if(x<=0 || k<0 || k>120)return 0;

    if(dp.find({x,k})!=dp.end())return dp[{x,k}];

    int idx=upper_bound(zn.begin(),zn.end(),x)-zn.begin();
    idx--;
    int y=zn[idx];

    return dp[{x,k}]=dfs(y-1,k)+dfs(x-y,k-1);
}

int g(int l,int r,int k){
    return dfs(r,k)-dfs(l-1,k);
}

void jarvis()
{
    int l,r,k;
    cin>>l>>r>>k;
    
    cout<<g(l,r,k)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    zn_init();

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}