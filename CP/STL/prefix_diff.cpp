#include <bits/stdc++.h>
using namespace std;
// f->range update and point query
#define mod 1000000007
#define int long long
typedef pair<int,int> pp;
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
    
    int n,k;

    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>prefix_diff(n,0);
    prefix_diff[0]=a[0];
    for(int i=1;i<n;i++){
        prefix_diff[i]=a[i]-a[i-1];
    }

    while(k--){
        int l,r,d;
        cin>>l>>r>>d;
        l--;
        r--;
        prefix_diff[l]+=d;
        (r+1<n)?prefix_diff[r+1]-=d:0;
    }
    for(int i=1;i<n;i++){
        prefix_diff[i]+=prefix_diff[i-1];
    }

    for(int i=0;i<n;i++){
        cout<<prefix_diff[i]<<" ";
    }
    return 0;
}