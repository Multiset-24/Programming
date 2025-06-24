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

const int inf=1e9;
void jarvis()
{
    int n;
    cin>>n;
    vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>g[i][j];
    }
    vector<int>dm(2*n-1,inf);//diagonal minimum
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)dm[j-i+n-1]=min(dm[j-i+n-1],g[i][j]);
    }
    int ans=0;
    for(auto it:dm){
        ans+=max(0LL,-it);
    }
    cout<<ans<<endl;
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