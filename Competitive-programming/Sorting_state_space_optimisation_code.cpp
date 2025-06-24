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

typedef pair<int,int> p;
int n;
int a,b;

/*
    Question-> We have n pairs consisting of values (ai,bi) , now we have divide it in 2 sets such that the score of values in A and B is maximum , also if we take ai then we can not take bi forward.alignas

    constrainst-> Bag A size can not be greater than x and Bag B size can not be greater than y.alignas

    1<=a,b<=n<=1000

*/

int dp[1005][1005];
vector<p>scores;

//optimised code
int optimised_dfs(int i,int b_left){
    if(i==n){
        if(b_left==0)return 0;
        else return -1e15;
    }
   
    if(dp[i][b_left]!=-1)return dp[i][b_left];

    int a_taken=i-(b-b_left);
    int a_left=a-a_taken;
    int max_score=0;

    if(a_left<a){
        max_score=optimised_dfs(i+1,b_left)+scores[i].first;
    }
    
    max_score=max(max_score,optimised_dfs(i+1,b_left-1)+scores[i].second);
    
    return dp[i][b_left]=max_score;
}

void jarvis()
{
    cin>>n>>a>>b;
    scores.assign(n,{0,0});
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>scores[i].first>>scores[i].second;
    }

    sort(scores.begin(),scores.end());// sorting is done such that choosing becomes greedy for A bag 

    cout<<optimised_dfs(0,b);
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