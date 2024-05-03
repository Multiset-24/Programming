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
        string s;
        read(s);

        u_mp<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        int duplicates = 0;
        for(auto i:mp){
            if(i.second>=2){
                duplicates++;
            }
        }

        int non_duplicated=mp.size()-duplicates;

        int ans=duplicates+non_duplicated/2;

        cout<<ans<<endl;


    }
    return 0;
}