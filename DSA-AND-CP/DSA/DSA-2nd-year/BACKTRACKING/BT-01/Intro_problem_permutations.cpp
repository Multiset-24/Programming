/*Question- you are given a string consisting of small alphabets. Consider no repition in the characters print all possible permatations of the given string. Note: Ordering does not matter */

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
void print_permutaions(string s, string ans) {
    if(s.size() == 0) {
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < s.size(); i++) {
        string temp = s;
        temp.erase(i, 1);//erase function-syntax- s.erase(starting_index, length) time complexity-O(n)
        print_permutaions(temp, ans + s[i]);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    read(s);

    print_permutaions(s, "");
    return 0;
}