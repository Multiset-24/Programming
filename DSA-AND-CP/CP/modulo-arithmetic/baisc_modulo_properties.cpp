#include <bits/stdc++.h>
using namespace std;

//find the number of diagonals of n-gon when n is too large


#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
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

int binpow(int a,int b){

    int res=1;

    while(b>0){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }

    return res%mod;
}
void jarvis(){
    int n;
    cin>>n;

    int ans=((n%mod)*((n-3)%mod))%mod;

    ans=((ans%mod)*(binpow(2,mod-2)))%mod;//fermets theorem
    

    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin>>q;

    while(q--){
        jarvis();
    }
    return 0;
}