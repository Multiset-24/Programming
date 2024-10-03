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
void print_permutaions_using_backtracking(string &s, int i) {
    if(i == s.size()) {
        cout << s << endl;
        return;
    }
    unordered_set<char> used;
    for(int j = i; j < s.size(); j++) {
        if(used.count(s[j])) continue;//if the character is already used then skip it (pruning the tree)
        used.insert(s[j]);
        swap(s[i], s[j]); 
        print_permutaions_using_backtracking(s, i + 1);
        swap(s[i], s[j]);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    read(s);

    print_permutaions_using_backtracking(s, 0);
    return 0;
}

