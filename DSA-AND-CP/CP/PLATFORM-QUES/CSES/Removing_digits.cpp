#include <bits/stdc++.h>
using namespace std;
vector<int>digits(int n){
    vector<int>dig;

    while(n>0){
        if(n%10!=0){
        dig.push_back(n%10);
        }
        n/=10;
    }

    return dig;
}
vector<int>dp;
int f(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    
    if(dp[n]!=-1) return dp[n];

    vector<int>d=digits(n);
    int result=INT_MAX;
    for(int i=0;i<d.size();i++){
        result=min(f(n-d[i]),result);
    }
    return dp[n]=1+result;
}

int fbt(int n){
    
}
int main() {
    int n;
    cin>>n;
    dp.resize(1000005,-1);
    cout<<f(n);
    return 0;
}