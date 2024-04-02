#include <bits/stdc++.h>
using namespace std;
//leetcode link-https://leetcode.com/problems/isomorphic-strings/
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

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,char>mp_s;//mapping of s to t
        unordered_map<char,char>mp_t;//mapping of t to s
        for(int i=0;i<s.size();i++){
            if(mp_s.find(s[i]) ==mp_s.end() && mp_t.find(t[i]) ==mp_t.end()){
                mp_s[s[i]]=t[i];
                mp_t[t[i]]=s[i];
            }
            else if(mp_s[s[i]]!=t[i] || mp_t[t[i]]!=s[i]) return false;
        }
        return true;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,t;
    read(s,t);
    Solution ob;
    cout<<ob.isIsomorphic(s,t)<<endl;


    return 0;
}