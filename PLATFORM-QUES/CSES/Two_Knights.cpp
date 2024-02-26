#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

int main() {
    int k;
    cin>>k;

    for(ll i=1;i<=k;i++){
        ll total_ways=((ll)(i*i)*(ll)(i*i-1))/2;
        ll required_ways=total_ways-4*(ll)(i-1)*(ll)(i-2);

        cout<<required_ways<<endl;
    }
    return 0;
}