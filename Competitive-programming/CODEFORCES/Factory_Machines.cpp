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
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define prin9t_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

int check(int time,vector<int>&times,int t){
    int cnt=0;

    for(auto it:times){
        cnt+=(time/it);
    }
    return cnt>=t;
}
void jarvis()
{
   
    int n,t;
    cin>>n>>t;

    vector<int>times;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        times.push_back(x);
    }
    sort(times.begin(),times.end());
    int lo=0;
    int hi=times[0]*t;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(mid,times,t)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }


    cout<<ans<<endl;
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