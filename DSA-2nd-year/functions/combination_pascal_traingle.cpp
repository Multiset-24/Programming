#include <bits/stdc++.h>
using namespace std;
int nfact(int n){
    int nfact=1;
    if(n==0){
        return 1;
    }else{
    for (int i = 1; i <=n ; i++)
    {
       nfact=nfact*i;
    }
    }
    return nfact;
}
int combination(int n,int r){
    int nCr=nfact(n)/(nfact(n-r)*nfact(r));
}
void PT(int n){
    for (int i = 0; i < n; i++)
 {
    for (int j = 0; j <= i; j++)
    {
       cout<<combination(i,j)<<" ";
    }
    cout<<endl;
 }
}
int main() {
    int n;
 cin>>n;
 PT(n);
    return 0;
}