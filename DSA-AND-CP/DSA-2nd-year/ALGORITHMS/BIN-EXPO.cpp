#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

ll _pow(ll n){
    ll result=1;
    ll base=2;
    while(n>0){
        if(n%2==1){
            result*=base;
        }
        base*=base;
        n/=2;//move to the next bit of the exponent
    }

    return result%mod;
}
int main() {
 
    return 0;
}