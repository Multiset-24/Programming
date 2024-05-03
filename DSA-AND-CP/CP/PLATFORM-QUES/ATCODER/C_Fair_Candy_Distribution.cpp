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
    
    int n,k;
    read(n,k);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        read(a[i]);
    }
    vector<int> b(n);
    b=a;
    sort(b.begin(),b.end());

    u_mp<int,int>helper;
    for(auto it:b){
        helper[it]=k/n;
    }
    
    k=k%n;

    while(k--){
        helper[b[k]]++;
    }

    for(int i=0;i<n;i++){
        cout<<helper[a[i]]<<endl;
    }
    return 0;
}