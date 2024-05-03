#include <bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1068
#define mod 1000000007
void weird_algorithm(long long n){
    while(n!=1){
        if(n%2==0){
            n=n/2;
            cout<<n<<" ";
        }
        else{
            n=n*3+1;
            cout<<n<<" ";
        }
    }
}
int main() {
    long long  n;
    cin>>n;
    cout<<n<<" ";
    weird_algorithm(n);

    return 0;
}