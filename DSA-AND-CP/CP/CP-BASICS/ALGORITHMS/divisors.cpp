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
vector<int> divisors(int n) {
    vector<int> divs;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            divs.push_back(i);
            if(i!=n/i) {
                divs.push_back(n/i);
            }
        }
    }
    return divs;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> divs = divisors(n);
    for(int i=0;i<divs.size();i++) {
        cout<<divs[i]<<" ";
    }
    return 0;
}