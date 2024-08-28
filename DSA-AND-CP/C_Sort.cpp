/*---------------------------------------------------------------------------------------------------
Saurav:Hello Jarvis !!
　 ￣￣\　　　　　　　 ∧＿∧    Jarvis:Hello Master !! you gotta do this problem because your hypothetical
　　　  \　 ∧＿∧ 　（´<_｀ ）/￣￣    hardworking crush who is based on the real person
　　　　 （ ´_ゝ`）　/　 ⌒|           must be studying hard.....
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
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

void jarvis()
{
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefix_a(n+1, vector<int>(26, 0));
    vector<vector<int>> prefix_b(n+1, vector<int>(26, 0));

    for (int j = 1; j <=n; j++)
    {

            prefix_a[j][a[j-1] - 'a']++;
            prefix_b[j][b[j-1] - 'a']++;

        for (int i = 0; i < 26 && j>=1; i++)
        {
            prefix_a[j][i] = prefix_a[j - 1][i] + prefix_a[j][i];
            prefix_b[j][i] = prefix_b[j - 1][i] + prefix_b[j][i];
        }
    }

    print_2dvector(prefix_a);
    print_2dvector(prefix_b);

    while(k--){
        int l,r;
        cin>>l>>r;

        int ans=0;
        for(int i=0;i<26;i++){
            int cnt_a=prefix_a[r][i]-prefix_a[l-1][i];
            int cnt_b=prefix_b[r][i]-prefix_b[l-1][i];

            if(cnt_a>cnt_b) ans+=(cnt_a-cnt_b);
        }

        cout<<ans<<endl;
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