#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
#define r_vector(v, n) vector<int> v(n+1,0); for(int i = 1; i <=n; i++) cin >> v[i];
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
//This is policy based data structure for ordered sets which gives additional features like find_by_order(x) and order_of_key(x);

int gcd(int a,int b){
    if(a==0){
        return b;
    }

    return gcd(b%a,a);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'


int helper(string &s,char a,char b){
    int n=s.size();
    int min_op=INT_MAX;
    char prev='-1';
    int prev_idx=-1;

   for(int i=0;i<n;i++){
    if(s[i]==a){
        prev=a;
        prev_idx=i;
    }

    if(prev!='-1' && s[i]==b){
        int op=(n-prev_idx-2);
        min_op=min(min_op,op);
    }
   }
    return min_op;
}

void jarvis(){
   string s;
   cin>>s;
    int n=s.size();
   //we need to find the minimum moves that we need to perform to form last 2 digits as 25 or 50 or 00 or 75 so we check for each of them and find the minm number of operations

   //for 00 

   char prev='-1';
    int prev_idx=-1;
    int min_op=INT_MAX;
   for(int i=0;i<n;i++){
    if(s[i]=='0' && prev=='-1'){
        prev='0';
        prev_idx=i;
    }
    
    if(prev!='-1' && s[i]=='0'){
        int op=(n-prev_idx-2);
        min_op=min(min_op,op);
        prev_idx=i;
    }
   }

   min_op = min({min_op, (int)helper(s, '2', '5'), (int)helper(s, '5', '0'), (int)helper(s, '7', '5')});

   cout<<min_op<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q;
    cin>>q;
    while(q--){
        jarvis();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
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