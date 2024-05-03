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

vector<int> dp(4001,-1);

int cut_ribbon(int n,int a,int b,int c){
    if(n==0) return 0;
    if(n<0) return INT_MIN;
    

    if(dp[n]!=-1) return dp[n];
    return dp[n]=1+max({
        cut_ribbon(n-a,a,b,c),
        cut_ribbon(n-b,a,b,c),
        cut_ribbon(n-c,a,b,c),
    });

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l,a,b,c;
    read(l,a,b,c);

    cout<<cut_ribbon(l,a,b,c);

    return 0;
}