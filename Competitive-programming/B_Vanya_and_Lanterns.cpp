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

void jarvis()
{
    int n,l;
    cin>>n>>l;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    unique(a.begin(),a.end());
    n=a.size();
    long double ans=a[0]*1.0;
    for(int i=0;i<n-1;i++){
        long double d=(a[i+1]-a[i])/2.0;
        ans=max(d,ans);
    }
    long double d=1.0*(l-a[n-1]);
    ans=max(ans,d);
    cout<<fixed<<setprecision(10)<<ans<<endl;
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