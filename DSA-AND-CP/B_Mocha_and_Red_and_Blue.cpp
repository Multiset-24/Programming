#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#define print_set(s)             \
    {                            \
        cout << #s << " = {";    \
        for (auto &elem : s)     \
            cout << elem << " "; \
        cout << "}" << endl;     \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_set(s)
#define print_2dvector(v)
#endif
#define endl '\n'

// Enter your main logic here !!

void jarvis()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int strt = 0;

    while (strt < n && s[strt] == '?')
        strt++;

    // Fill the characters before the first non-'?' character
    if (strt < n) {
        char c = s[strt];
        for (int i = strt - 1; i >= 0; --i) {
            if (s[i + 1] == 'R')
                s[i] = 'B';
            else
                s[i] = 'R';
        }
    }

    // Fill the characters after the first non-'?' character
    for (int i = strt; i < n; ++i) {
        if (s[i] == '?') {
            if (i > 0 && s[i - 1] == 'R')
                s[i] = 'B';
            else if (i > 0 && s[i - 1] == 'B')
                s[i] = 'R';
        }
    }

    // If the entire string was '?'
    if (strt == n) {
        for (int i = 0; i < n; ++i) {
            s[i] = (i % 2 == 0) ? 'R' : 'B';
        }
    }

    cout << s << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
