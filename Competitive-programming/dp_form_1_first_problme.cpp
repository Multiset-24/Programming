#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
int n,A,B;

int dp[101][101][101][11];
int rec(int i,int a,int b,int last){
    // prune
    // base
    if(i==n){
        if(a==0&&b==0){
            return 1;
        }else{
            return 0;
        }
    }
    // cache check
    if(dp[i][a][b][last]!=-1)
        return dp[i][a][b][last];
    // transition
    int ans = 0;
    for(int x=0;x<=9;x++){
        if(x==last)continue;
        ans += rec(i+1,(a*10+x)%A,(b+x)%B,x);
        ans %= MOD;
    }
    // save and return
    dp[i][a][b][last]=ans;
    return ans;
}

string final_num;
void generate(int i,int a,int b,int last){
    // prune
    // base
    if(i==n){
        return;
    }
    // transition
    int ans = 0;
    for(int x=0;x<=9;x++){
        if(x==last)continue;
        if(rec(i+1,(a*10+x)%A,(b+x)%B,x)>0){ // There is a issue here???
            final_num += to_string(x);
            generate(i+1,(a*10+x)%A,(b+x)%B,x);
            return;
        }
    }
}

signed main()
{
    cin>>n>>A>>B;
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,0,0,10);
    cout<<ans<<endl;
    // int k; Find the kth number??
    generate(0,0,0,10);
    cout<<final_num<<endl;
}