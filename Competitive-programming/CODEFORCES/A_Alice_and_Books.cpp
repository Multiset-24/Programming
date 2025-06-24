#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
#define r_vector(v, n) vector<int> v(n); for(int i = 0; i < n; ++i) cin >> v[i];
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
//This is policy based data structure for ordered sets which gives additional features like find_by_order(x) and order_of_key(x);

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

void jarvis(){
   int n;
   cin>>n;

   r_vector(v,n);

   int ans=v[n-1];

   int maxm=INT_MIN;

   for(int i=0;i<n-1;i++){
    if(maxm<v[i]) maxm=v[i];
   }

   ans+=maxm;

   cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q;
    cin>>q;
    while(q--){
        jarvis();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}