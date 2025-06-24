#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

string preprocess(string s){
    string t="@#";//adding sentinal characters

    for(int i=0;i<s.size();i++){
        t+=s[i];
        t+="#";
    }

    return t+"&";//adding sentinal characters
}

vector<int> manacher(const string &s) {
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0); 
    int c = 0, r = 0;    

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * c - i; 
        if (i < r) {
            p[i] = min(r - i, p[mirror]);
        }

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    return p; 
}


void jarvis()
{
    string s;
    
    cin>>s;


    vector<int>ma=manacher(s);//manacher array

    int lspi=0;//longest suffix pallindrome index
    int max_len=0;//maximum length 
    for(int i=ma.size()-2;i>=1;i--){//removed indices of sentinal characters
            int si=(i-ma[i])/2;
            if(si+ma[i]-1==s.size()-1){
                lspi=si;
                max_len=ma[i];
            }
    }
    
    for(int i=0;i<lspi;i++){
        cout<<s[i];
    }
    for(int i=lspi;i<lspi+max_len;i++){
        cout<<s[i];
    }
    for(int i=lspi-1;i>=0;i--){
        cout<<s[i];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}