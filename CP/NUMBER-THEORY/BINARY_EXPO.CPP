#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;
int binary_exponentiation(int a,int b){
    int res=1;

    while(b>0){
        if(b&1){
            res*=a;
        }
        a*=a;
        b/=2;
    }

    return res;
}
int main() {
    int a,b;    
    cin>>a>>b;
    cout<<binary_exponentiation(a,b)<<endl;
    return 0;
}