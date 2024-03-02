#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;
#define u_mp unordered_map
#define DEBUG 
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;

    u_mp<int,int>mp;
    while(k--){
        int s;
        int x;
        cin>>s>>x;
        if(s==1){
            mp[x]++;
        }
        else{
            cout<<mp[x]<<endl;
        }
    }
    return 0;
}