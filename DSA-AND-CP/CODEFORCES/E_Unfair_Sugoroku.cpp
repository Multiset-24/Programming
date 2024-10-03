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

#define MOD 1000000007
#define mod 998244353
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


int binpow(int a, int b)
{
    int ans = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }

    return ans;
}

int modinv(int a)
{
    return binpow(a, mod - 2) % mod;
}

int dp[105][105][3];
int rec(int i,int j,int f,int a,int b,int n,int p,int q){
    if(i>=n)return 1;
    if(j>=n) return 0;

    if(dp[i][j][f]!=-1) return dp[i][j][f];
    int ans=0;
    if(f==1){3
        for(int k=1;k<=p;k++){
            ans+=rec(min(i+k,n),j,0,a,b,n,p,q);
        }
        ans=ans*modinv(p);
    }

    if(f==0){
        for(int k=1;k<=q;k++){
            ans+=rec(i,min(j+k,n),1,a,b,n,p,q);
        }
        ans=ans*modinv(q);
    }

    return dp[i][j][f]=ans%mod;
}
void jarvis()
{
    int n, a, b, p, q;

    cin >> n >> a >> b >> p >> q;
    memset(dp,-1,sizeof(dp));
    cout<<rec(a,b,1,a,b,n,p,q);
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