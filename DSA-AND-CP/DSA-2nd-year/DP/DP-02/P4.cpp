#include <iostream>
using namespace std;
#include<vector>
// https://www.spoj.com/problems/MCOINS/
vector<int>dp;
bool f(int n,int k,int l){
    if(n==1||n==k||n==l) return 1;

    if(dp[n]!=-1) return dp[n];

   dp[n]=!((f(n-1,k,l) && (n-k>=1)?f(n-k,k,l):1 && (n-k>=1)?f(n-l,k,l):1));


    return dp[n];
}

void fbt(int k,int l,vector<int>coins){
    dp.clear();
    dp.resize(1000005,0);

    dp[1]=1;
    dp[k]=1;
    dp[l]=1;

    for(int i=2;i<1000005;i++){
        if(i!=k&&i!=l){
            dp[i]=!(dp[i-1]&&(i-k>=1)?dp[i-k,k,l]:1 && (i-k>=1)?dp[i-l,k,l]:1);
        }
    }
    string result;
    for(int i=0;i<coins.size();i++){
        if(dp[coins[i]]==1){
            result+='A';
        }
        else{
            result+='B';
        }
    }
    cout<<result;
}
int main() {
    dp.clear();
    dp.resize(10000006,-1);
    int k,l,m;
    cin>>k>>l>>m;

    vector<int>coins(m);
    for(int i=0;i<m;i++){
        cin>>coins[i];
    }
    // string result="";
    // for(int i=0;i<m;i++){
    //     int num;
    //     cin>>num;

    //     if(f(num,k,l)==1){
    //         result+='A';
    //     }
    //     else{
    //         result+='B';
    //     }
    // }

    // cout<<result;

    fbt(k,l,coins);
    return 0;
}