#include <bits/stdc++.h>
using namespace std;
int f(int a,int b){
    if(a==0) return b;

    return f(b%a,a);
}
int main() {
    cout<<f(24,12)<<" ";
    cout<<f(12,24)<<" ";
    cout<<__gcd(12,24);//use of stl in this
    return 0;
}