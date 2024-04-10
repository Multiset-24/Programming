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
    
    int q;

    
    read(q);

    while(q--){
        int n,k;
        read(n,k);

        vector<int> a(n);

        int sum=0;
        for(int i=0;i<n;i++){
            read(a[i]);
            sum+=a[i];
        }

        if(sum<=k){
            cout<<n<<endl;
            continue;
        }
        int i=0, j=n-1;
        while(i <= j && k > 0) {
            if(a[i] > 0) {
                a[i]--;
                k--;
            }
            if(k == 0) break;
            if(a[j] > 0) {
                a[j]--;
                k--;
            }
            i++;
            j--;
        }
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=0){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
