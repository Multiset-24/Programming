#include <bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1083
#define mod 1000000007
#define ll long long 

ll missing_num(vector<ll>&num){
    for(int i=1;i<num.size();i++){
        if(num[i]!=i) return i;
    }
}
int main() {
    int n;
    cin>>n;

    vector<ll>num(n+1,-1);

    for(int i=0;i<n-1;i++){
        ll k;
        cin>>k;
        num[k]=k;
    }

    cout<<missing_num(num);
    return 0;
}