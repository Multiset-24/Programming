#include <bits/stdc++.h>
using namespace std;

//Given a number n , you can perform below 3 operations on it 
// 1-->reduce n to n-1
// 2-->if n is divisible by 2 than make it n/2
// 3-->if n is divisble by 3 than make it n/3
//return the minimum number of steps required to make the number 1.

//recursive approach
int f(int n ){
    if(n==1) return 0;
    if(n==3 || n==2) return 1;


    return 1+min({f(n-1),(n%2==0)?f(n/2):INT_MAX,(n%3==0)?f(n/3):INT_MAX});

}

//dp approach
vector<int>dp;
int ftb(int n ){
    if(n==1) return 0;
    if(n==3 || n==2) return 1;

    if(dp[n]!=-1) return dp[n];
    return 1+min({ftb(n-1),(n%2==0)?ftb(n/2):INT_MAX,(n%3==0)?ftb(n/3):INT_MAX});

}

//bottom to top approach

int fbt(int n ){
    if(n==1) return 0;
    if(n==3 || n==2) return 1;


    return 1+min({f(n-1),(n%2==0)?f(n/2):INT_MAX,(n%3==0)?f(n/3):INT_MAX});

}
int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<f(n);
    return 0;
}