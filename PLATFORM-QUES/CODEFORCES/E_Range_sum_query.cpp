#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,Q;
    cin>>n>>Q;

    vector<int>prefix_sum(n+1);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1) prefix_sum[1]=x;
        else{
            prefix_sum[i]=prefix_sum[i-1]+x;
        }
    }

    while(Q--){
        int strt,end;
        cin>>strt>>end;

        cout<<prefix_sum[end]-prefix_sum[strt-1]<<endl;
    }
    return 0;
}