#include <bits/stdc++.h>
using namespace std;
//power function(logarithmic)
int pow2(int a,int b){
    if(b==1) return a;
    int ans=pow2(a,b/2);
    if(b%2==0) return ans*ans;
    else{
        return ans*ans*a;
    }
}
int main() {
 cout<<pow2(2,5);
    return 0;
}