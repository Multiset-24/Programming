#include <bits/stdc++.h>
using namespace std;
//Given a positive integer, return true if it is a power of 2.
bool powcheck(int a ,int n){
    if(n%a!=0){
        return false;
    }
    else if(n%a==0){
        powcheck(a,n/a);
        return true;
    }
}
int main() {
    int a ,n;
    cin>>a>>n;
    cout<<powcheck(a,n);
    return 0;
}