#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
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

int n;
bool check(int k){
    return k*(k+1)<=n/13;
}
void jarvis()
{
    cin>>n;
    int l=1,h=1e9;
    int ans=-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(check(m)){
            l=m+1;
            ans=m;
        }
        else{
            h=m-1;
        }
    }
    char c=(ans==-1?'a'+n-1:'a'+((n-13LL*ans*(ans+1))/(ans+1))-1);
    cout<<c<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}