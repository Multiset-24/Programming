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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    vector<int>p(n+1,0);
    int sc=0;
    for(int i=1;i<=n;i++){
        sc+=a[i-1];
        p[i]=a[i-1]+p[i-1];
    }
    int sm=1e17;
    for(int x=0;x<=k;x++){
        sm=min(sm,p[2*x]+p[n]-p[n-k+x]);
    }
    cout<<sc-sm<<endl;
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