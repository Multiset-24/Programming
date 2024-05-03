#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

int main() {
    int n;
    cin>>n;

    vector<int>num(n);

    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int x;
    cin>>x;

    int res=-1;

    for(int i=0;i<n;i++){
        if(num[i]==x){
            res=i;
            break;
        }
    }

    cout<<res;
    return 0;
}