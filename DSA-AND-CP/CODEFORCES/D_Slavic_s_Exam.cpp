/*---------------------------------------------------------------------------------------------------
Saurav:Hello Jarvis !!
　 ￣￣\　　　　　　　 ∧＿∧    Jarvis:Hello Master !! JAI BAJARANG BALI
　　　  \　 ∧＿∧ 　（´<_｀ ）/￣￣    Give me some sunshine, give me some rain give me another chacne to
　　　　 （ ´_ゝ`）　/　 ⌒|           Grow up once again....
　　　　／　　　＼　 　  |　|           sab moh maya hai....
　　　 /　　 /￣￣￣￣/　　|             waiting....
　 ＿_(__ﾆつ/　   _ / .| .|＿＿＿＿
　 　　　＼/_______/　（u　⊃
---------------------------------------------------------------------------------------------------*/
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
pair<int, pair<int, int>> lcs_with_indices(const string &X, const string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Length of LCS
    int length = dp[m][n];

    // Backtrack to find the start and end indices
    int i = m, j = n;
    int end_index = -1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            if (end_index == -1) {
                end_index = i - 1;
            }
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    int start_index = i;

    return {length, {start_index, end_index}};
}

void jarvis()
{
    string s, t;
        cin >> s >> t;

        int n = s.size();
        int m = t.size();

        // Check if t can be a subsequence of s
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s[i] == t[j] || s[i] == '?') {
                j++;
            }
        }

        if (j < m) {
            cout << "NO" << endl;
        } else {
            // Replace '?' in s to make t a subsequence
            j = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    if (j < m) {
                        s[i] = t[j++];
                    } else {
                        s[i] = 'a'; // Replace remaining '?' with any character
                    }
                }
                else if(s[i]==t[j]){
                    j++;
                }
            }
            cout << "YES" << endl;
            cout << s << endl;
        }
    
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

// MISTAKES THAT I AM MAKING //

/*
1. Try to solve 2 problem above your limit
2. Always check if you have declared any variable for input taking have you taken input or not this can give bad_alloc error
3. max and min function are made for taking arguments of same type i.e max(x,y) is valid only if x and y are of same type
4. Always make sure you apply your logic after taking all the inputs do not do mistake like that of https://codeforces.com/problemset/problem/1685/A (circular minmax)
5. always check for memory for global and local variables it may give std allocated throwback error
6. Sometimes it's better to think of subarray approach rather than more brute forces approach .
7. do not go in floating points like that of internal pow function
8. Always beware of loops sometimes for decrementing loops we use i++ instead of i-- !
9. while debugging try to do stress testing .
10. always make prefix sum array of size n+1.



*/