#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        for(int j=0;j<3;j++){
            cout<<i<<" ";
            i++;
        }
        i++;
        cout<<"PUM\n";
    }
    return 0;
}