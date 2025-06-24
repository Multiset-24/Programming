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

string a,b;
int dp[3005][3005];
string lcs;

int solve(int i,int j){
    if(i>=a.size() || j>=b.size())return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j])return dp[i][j]=1+solve(i+1,j+1);

    return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
}

void generate(int i,int j){
    if(i>=a.size() || j>=b.size())return ;

    if(a[i]==b[j]){
        lcs.push_back(a[i]);
        generate(i+1,j+1);
        return;
    }

    if(solve(i+1,j)>solve(i,j+1)){
        generate(i+1,j);
    }
    else{
        generate(i,j+1);
    }

    return ;
}
void jarvis()
{
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));

    generate(0,0);

    cout<<lcs<<endl;

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