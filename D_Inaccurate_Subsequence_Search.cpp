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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    read(q);

    while(q--){
        int n,m,k;
        read(n,m,k);

        vector<int> a(n);

        for(int i=0;i<n;i++){
            read(a[i]);
        }

        u_mp<int,int> mp;

        for(int i=0;i<m;i++){
            int x;
            read(x);
            mp[x]++;
        }
        
        int i=0;
        int j=0;

        for(int k=0;k<m;k++){
            if(mp.find(a[k])!=mp.end() ){
                j++;
            }
        }


        
    }
    return 0;
}