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
        int d;
        read(d);
        int a = 1+d;
        while(true){
            bool flag = true;
            for(int i=2; i*i<=a; i++){
                if(a%i==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                break;
            }
            a++;
        }
        
        int b = a+d;
        while(true){
            bool flag = true;
            for(int i=2; i*i<=b; i++){
                if(b%i==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                break;
            }
            b++;
        }
        cout << a*b << endl;
    }
    return 0;
}