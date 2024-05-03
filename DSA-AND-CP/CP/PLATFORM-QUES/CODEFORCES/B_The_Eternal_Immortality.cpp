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
    
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    int a,b;
    read(a,b);
    
    int number_of_times_reincarnated=1;

    while(b!=a){
        number_of_times_reincarnated*=b;
        number_of_times_reincarnated%=10;
        if(number_of_times_reincarnated==0) break;
        b--;
    }

    cout<<number_of_times_reincarnated<<endl;


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}