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
    int a,b;
    read(a,b);

    int cnt=0;
    u_st<int>power_of_5;

    for(int i=1;i<=a+b;i++)
    {
        if(i%5==0)
        {
            power_of_5.insert(i);
        }
    }
    for(int i=1;i<=min(a,b);i++)
    {
       for(auto x:power_of_5)
       {
           if(x-i<=max(a,b) && x-i>0)
           {
                cout<<i<<" "<<x-i<<endl;
               cnt++;
           }
       }
    }

    cout<<cnt<<endl;
    return 0;
}