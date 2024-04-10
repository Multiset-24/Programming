#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

vector<vector<int>>dp(101,vector<int>(3,-1));

int solve(vector<int>&a,int n,int i,int prev){
    if(i==n){
        return 0;
    }

    if(dp[i][prev]!=-1){
        return dp[i][prev];
    }

    int ans=0;

    if(a[i]==0){
        ans=1+solve(a,n,i+1,0);
    }else if(a[i]==1){
        if(prev==1){
            ans=1+solve(a,n,i+1,0);
        }else{
            ans=min(1+solve(a,n,i+1,0),solve(a,n,i+1,1));
        }
    }else if(a[i]==2){
        if(prev==2){
            ans=1+solve(a,n,i+1,0);
        }else{
            ans=min(1+solve(a,n,i+1,0),solve(a,n,i+1,2));
        }
    }else{
        if(prev==0){
            ans=min({1+solve(a,n,i+1,1),solve(a,n,i+1,2),solve(a,n,i+1,0)});
        }else if(prev==1){
            ans=min(solve(a,n,i+1,2),1+solve(a,n,i+1,0));
        }else{
            ans=min(solve(a,n,i+1,1),1+solve(a,n,i+1,0));
        }
    }

    return dp[i][prev]=ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    read(n);

    vector<int> a(n);

    for(int i=0;i<n;i++){
        read(a[i]);
    }

    cout<<solve(a,n,0,0)<<endl;

    
    return 0;
}