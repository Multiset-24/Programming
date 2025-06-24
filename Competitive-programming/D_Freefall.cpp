#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
using  lld = long  double;
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

lld time(int x,int a,int b){
    return lld(b)*x+lld(a)/sqrt(x+1);
}
void jarvis()
{
    int a,b;
    cin>>a>>b;

    int lo=0,hi=(a+b-1)/b,ans=-1;

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(time(mid+1,a,b)>=time(mid,a,b)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }

    cout<<fixed<<setprecision(10)<<time(ans,a,b)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}