//understand dp using fibonacci series ;
#include <bits/stdc++.h>
using namespace std;

//memoisation approach for fibonacci series-------
long long fnM(long long n,vector<long long>&helper){
    if(n<=1) return n;

    if(helper[n]!=-1) return helper[n];

    return helper[n]=fnM(n-1,helper)+fnM(n-2,helper);
}
//-------Tabulation approach
long long fT(long long n){
    vector<long long>helper(n+1);
    helper[0]=0;
    helper[1]=1;
    for(int i=2;i<=n;i++){
         helper[i]=helper[i-1]+helper[i-2];

    }
    return helper[n];
}


//this is the bottom up approach whose tc is O(n) and space complexity is optimised to O(1)----Tabulation(modified)
long long fTM(long long n){
    long long a=0;
    long long b=1;
    while(n-->1){
        long long sum=a+b;
        a=b;
        b=sum;
    }
    return b;
}
int main() {
    long long n;
    cin>>n;
    cout<<fTM(n)<<endl;
    cout<<fT(n)<<endl;

    vector<long long>helper(n+1,-1);
    cout<<fnM(n,helper)<<endl;
    cout<<LLONG_MAX;
    return 0;
}