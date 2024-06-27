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

void jarvis(){
    int n,k;
    cin>>n>>k;
    int maxm=(n%2==0)?(n*n)/2:(n*n-1)/2;
    if(k%2!=0 || k>maxm){
        cout<<"NO"<<endl;
    }
    else{
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i]=i;
        }

        int strt=1;

        int ans=maxm;

        while(ans!=k){
            ans-=2;
            strt++;
        }
        
        reverse(v.begin()+strt,v.end());
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        jarvis();
    }
    return 0;
}