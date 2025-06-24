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

string s;
int dp[5005];

int alphacode(int level){
    if(level<0)return 1;

    if(dp[level]!=-1)return dp[level];

    int ans=0;

    if(s[level]!='0'){
        ans+=alphacode(level-1);
    }
    if(level>=1 && (s[level-1]-'0')*10+(s[level]-'0')>=10 &&(s[level-1]-'0')*10+(s[level]-'0')<=26){
        ans+=alphacode(level-2);
    }

    return dp[level]=ans;
}

void jarvis()
{
    while(true){
        cin>>s;
        if(s=="0"){
            return;
        }
        memset(dp,-1,sizeof(dp));

        cout<<alphacode(s.size()-1)<<endl;
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