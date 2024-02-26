#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

int main() {
    ios_base::sync_with_stdio(false);
    int k,s;
    cin>>k>>s;
    int count=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int x = s - i - j;
            if(x>=0 && x<=k){
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}