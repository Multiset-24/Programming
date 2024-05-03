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
    
    int n;
    read(n);
    
    //we need to find the sum of gcd of all possible tuples

    //gcd(a,b,c) = gcd(gcd(a,b),c) = gcd(a,gcd(b,c)) = gcd(gcd(a,c),b)

    //gcd(a,b) = gcd(b,a%b) = gcd(b,a-b) = gcd(a,b-a)
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                //gcd(i,j,k) = gcd(gcd(i,j),k) = gcd(gcd(i,k),j) = gcd(gcd(j,k),i)
                sum+=__gcd(__gcd(i,j),k);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}