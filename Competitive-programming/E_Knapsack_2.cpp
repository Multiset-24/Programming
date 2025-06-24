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

typedef pair<int,int> obj;
int n,w;
vector<obj>objects;

int dp[105][100005];

int rotated_dp(int i,int p){
    if(i==0){
        if(p==0)return 0;
        else if(p==objects[0].second)return objects[0].first;
        else return 1e15;
    }

    if(dp[i][p]!=-1)return dp[i][p];

    return dp[i][p]=min(rotated_dp(i-1,p-objects[i].second)+objects[i].first,rotated_dp(i-1,p));
}
void jarvis()
{
    cin>>n>>w;
    objects.assign(n,{0,0});
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>objects[i].first>>objects[i].second;
    }

    for(int p=100004;p>=0;p--){
        if(rotated_dp(n-1,p)<=w){
            cout<<p<<endl;
            return ;
        }
    }
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