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

vector<pi>Prime_factors(int n){
    vector<pi>factors;

    for(int i=2;i*i<=n;i++){
        int count=0;
        while(n%i==0){
            count++;
            n/=i;
        }
        factors.push_back({i,count});
    }

    if(n>1){
        factors.push_back({n,1});
    }

    return factors;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<pi>prime_factors=Prime_factors(n);

    for(auto it:prime_factors){
        if(it.second!=0)cout<<"("<<it.first<<","<<it.second<<")";
    }

    return 0;
}