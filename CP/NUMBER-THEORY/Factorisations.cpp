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

vector<int>PrimeFactors(int n){
    vector<int>factors;
    
    while(n%2==0){
        factors.push_back(2);
        n/=2;
    }

    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }

    if(n>2){
        factors.push_back(n);
    }

    return factors;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    read(n);

    vector<int>factors=PrimeFactors(n);

    for(auto i: factors){
        cout << i << " ";
    }

    
    return 0;
}