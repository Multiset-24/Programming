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
    

    vector<int> v = {1, 2, 3, 4, 5};

    // Declaring an iterator
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++) {
        cout << *it << " ";
    }
    it=v.begin();
    while(it!=v.end()) {
        cout << *it << " ";
        it++;
    }

    //for the vector of pairs
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it1;
    for(it1=vp.begin(); it1!=vp.end(); it1++) {
        cout << it1->first << " " << it1->second << endl;
    }


    return 0;
}