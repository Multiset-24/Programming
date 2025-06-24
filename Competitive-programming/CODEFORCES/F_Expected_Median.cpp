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

const int MOD =1e9+7;
// Function to calculate combinations
int C(int n, int r) {
    // cout<<n<<" "<<r<<endl;
    if (r > n) return 0;
    if(r==0) return 1;
    if (n - r < r) r = n - r;
    vector<int> dp(r + 1, 0);
    dp[0] = 1;

        // print_vector(dp);
    for (int i = 1; i <= n; i++) {
        for (int j =min(n,r); j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
        // print_vector(dp);
    }

    return dp[r];
}
vector<int>dp(2e5,-1);
int factorial(int n){
    if(n == 0){
        return 1;
    }
    if(dp[n] !=-1){
        return dp[n];
    }
    return dp[n] = factorial(n-1)*n%MOD;
}
int powerExponentation(int x,int n){
    int ans = 1;
    while(n>0){
        if(n%2 == 0){
            x = (x*x)%MOD;
            n = n/2;
        }
        else{
            ans = (ans*x)%MOD;
            n--;
        }
    }
    return ans;
}
int solve(int n,int r){
    if(n < r){
        return 0;
    }
    int nFactorial = factorial(n);
    int rFactorial = factorial(r);
    int nRFactorial  = factorial(n-r);
    return (nFactorial * ((powerExponentation(rFactorial,MOD-2)*powerExponentation(nRFactorial,MOD-2))%MOD))%MOD;
}
void jarvis() {
    int n, k;
    cin >> n >> k;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    // cout<<solve(n,k)<<endl;
    int cnt_o = 0;
    int cnt_one = 0;

    for (auto it : num) {
        if (it == 1) cnt_one++;
        else cnt_o++;
    }

    int min_req = k / 2 + 1;
    if (k > n || min_req > cnt_one) {
        cout << "0" << endl;
        return;
    }

    int ans = 0;
    for (int i = min_req; i <= cnt_one; i++) {
        if(k-i>=0){
        ans = (ans + (solve(cnt_one, i) * solve(cnt_o, k - i)) % MOD) % MOD;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--) {
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