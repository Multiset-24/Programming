#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
ll Number_spiral(ll x,ll y){
    if(x>y){
        if(x%2==0){
            return (x-1)*(x-1)+x+(x-y);
        }else return (x-1)*(x-1)+y;
    }
    else if(x==y){
        return (x-1)*(x-1)+x;
    }else{
        return (y%2==0)?(y-1)*(y-1)+x:(y-1)*(y-1)+(y-1)+(y-x+1);
    }
}
int main() {
    int n;
    cin>>n;
    while (n--)
    {
        ll x,y;
        cin >>x>>y;
        cout<<Number_spiral(x,y)<<endl;
    }
    
    return 0;
}