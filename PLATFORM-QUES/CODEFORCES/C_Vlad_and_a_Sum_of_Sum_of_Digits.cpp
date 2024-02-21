#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
vector<int>dp(1e7,-1);
int digit_sum(int x){
    int sum=0;

    while(x){
        sum+=(x%10);
        x/=10;
    }
    return sum;
}
int precompute(){
    dp[1]=1;


    for(int i=2;i<=2e5;i++){
        if(i<9){
            dp[i]=dp[i-1]+i;
        }
        else{
            dp[i]=dp[i-1]+digit_sum(i);
        }
    }
}

int solve(int n){
    cout<<dp[n]<<endl;
}
int main() {
    int n;
    cin>>n;
    precompute();
    while(n--){
        int k;
        cin>>k;

        solve(k);
    }
    return 0;
}