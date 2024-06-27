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

int kadan_s_algo(vector<int>&num){
    int sum=0,best=0;

    for(int i=0;i<num.size();i++){
        sum=max(num[i],sum+num[i]);
        best=max(best,sum);
    }

    return best;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    read(n);

    vector<int>num(n,0);

    for(int i=0;i<n;i++){
        read(num[i]);
    }

    cout<<kadan_s_algo(num);
    return 0;
}