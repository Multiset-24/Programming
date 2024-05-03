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
    

    int t;
    read(t);
    u_mp<string,vector<int>> mp;
    vector<pair<string,int>> v;
    while(t--) {
        string s;
        read(s);
        vector<int> temp(4);
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            int x;
            read(x);
            sum += x;
            temp[i] = x;
        }
        v.push_back({s,sum});
        mp[s] = temp;
    }
    sort(v.begin(),v.end(),[](pair<string,int> a, pair<string,int> b) { // sort in descending order using lambda function
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    return 0;
}