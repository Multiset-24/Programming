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

    string s;
    read(s);

    int n=s.size();

    vector<int>a;
    for(int i=0;i<n;i++){
        a.push_back(s[i]-'0');
    }

    int ans=(int)max(a[0]-1,(int)1)*(int)pow(9,n-1);
    int p=1;
    for(int i=0;i<n;i++){
        p*=a[i];
    }

    ans=max(ans,p);
    p=1;
    for(int i=0;i<n;i++){
        ans=(int)max(ans,(int)p*(a[i]-1)*(int)pow(9,n-1-i));
        p*=a[i];
    }


    cout<<ans<<endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}