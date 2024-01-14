#include <bits/stdc++.h>
using namespace std;
//stair path questions
int stairpath(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return stairpath(n-1)+stairpath(n-2);
}
/*
this about when he can take 3 steps at a time also
*/
int main() {
    int n;
    cin>>n;
    cout<<stairpath(n);
    return 0;
}