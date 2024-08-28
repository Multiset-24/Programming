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
int dp[10000];
int lis(vector<int> &num, int level)
{

    if (dp[level] != -1)
        return dp[level];

    int ans = 1;

    for (int i = 0; i < level; i++)
    {
        if (num[i] < num[level])
            ans = max(ans, 1 + lis(num, i));
    }

    return dp[level] = ans;
}
// lis modified version having time complexity of O(n*log(n));
vector<pair<int,int>>lis_modified(vector<int>&num){
    int n=num.size();
    vector<int> lis;//the length of lis is the length of longest subsequence 
    vector<pair<int,int>>subsequence;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < num[i])
        {
            lis.push_back(num[i]);
            subsequence.push_back({lis.size(),num[i]});
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), num[i]);
            *it = num[i];
            subsequence.push_back({it-lis.begin()+1,num[i]});
        }
    }

    return subsequence;
}

void bitonic(vector<int>&num){
    vector<pair<int,int>>normal=lis_modified(num);
    reverse(num.begin(),num.end());
    vector<pair<int,int>>reversed=lis_modified(num);
    reverse(num.begin(),num.end());

    int max_bitonic=0;
    int normal_length=0;
    int reversed_length=0;
    bool value=false;
    for(int i=0;i<normal.size();i++){
        if(normal[i].first+reversed[i].first>max_bitonic){
            max_bitonic=normal[i].first+reversed[i].first;
            normal_length=normal[i].first;
            reversed_length=reversed[i].first;
            value=normal[i].second==reversed[i].second;
        }
    }
    
    for(auto p:normal)cout<<"length "<<p.first<<" "<<"last element"<<p.second<<endl;

    cout<<"---------------\n";

    for(auto p:reversed)cout<<"length "<<p.first<<" "<<"last element"<<p.second<<endl;
}

void jarvis()
{
    int n;
    cin >> n;

    vector<int> num(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    memset(dp, -1, sizeof(dp));

    bitonic(num);
    
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