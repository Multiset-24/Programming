#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

int main() {
    int x,y,l,r;

    cin>>x>>y>>l>>r;

    int p=max(x,l);
    int q=min(y,r);

    if(p>q){
        cout<<-1<<endl;
        return 0;
    }
    else{
        cout<<p<<" "<<q;
    }
    return 0;
}