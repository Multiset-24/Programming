#include <bits/stdc++.h>
using namespace std;
//link atcoder-https://atcoder.jp/contests/abc177/tasks/abc177_a
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
    
    int n;
    read(n);
    int a[n];
    int no_of_odds=0;
    int no_of_evens=0;
    for(int i=0;i<n;i++) {
        read(a[i]);
        if(a[i]%2==0) {
            no_of_evens++;
        } else {
            no_of_odds++;
        }
    }
    
    if(no_of_odds%2==0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }


    return 0;
}