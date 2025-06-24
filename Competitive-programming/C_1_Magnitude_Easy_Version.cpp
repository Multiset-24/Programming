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
const int N=1e6;
void jarvis()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    map<int,pair<int,int>>dp;
    function<pair<int,int>(int)>dfs=[&](int i)->pair<int,int>{
        if(i==-1)return {0,0};
        if(dp.find(i)!=dp.end())return dp[i];
        pair<int,int>c=dfs(i-1);
        int p=c.first+a[i];
        int q=c.second+a[i];
        return dp[i]={max({p,q,abs(p),abs(q)}),min({p,q,abs(p),abs(q)})};
    };
    cout<<dfs(n-1).first<<endl; 
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