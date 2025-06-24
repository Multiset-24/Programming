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

void jarvis()
{
    int n;
    cin >> n;
    string s;
    cin >> s; 
    if (n == 2) {
        if (s == "AB") cout << "Alice";
        else cout << "Bob";
        cout<<endl;
        return;
    }
    int cntA = 0, cntB = 0;
    for (char c : s) if (c == 'A') cntA++; else cntB++;
    if (cntA == 1) {
        cout << "Bob"<<endl;
        return;
    }
    if (cntB == 1) {
        cout << "Alice"<<endl;
        return;
    }
    int maxB = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') maxB = i+1;
    }
    int ca = -1;
    if (s[0] == 'B') {
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'A') ca = max(ca, i+1);
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') ca = max(ca, i+1);
        }
    }
    if (ca > maxB) cout << "Alice"<<endl;
    else  cout << "Bob"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}