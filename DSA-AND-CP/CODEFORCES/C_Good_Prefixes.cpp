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
    int n;
    cin>>n;

    vector<int>num(n,0);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    vector<int>prefix_sum(n,0);
    prefix_sum[0]=num[0];

    for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+num[i];
    }

    vector<int>greatest(n,0);
    greatest[0]=num[0];
    for(int i=1;i<n;i++){
        greatest[i]=max(greatest[i-1],num[i]);
    }

    int count=0;

    for(int i=0;i<n;i++){
        if(prefix_sum[i]==2*greatest[i]){
            count++;
        }
    }

    cout<<count<<endl;

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