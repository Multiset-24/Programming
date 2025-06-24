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
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    vector<int>sf(n);
    sf[0]=a[n-1];
    for(int i=1;i<n;i++)sf[i]=sf[i-1]+a[n-i-1];
    int sm=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sm+=a[i];
        int sfidx=lower_bound(sf.begin(),sf.end(),sm)-sf.begin();
        if(sf[sfidx]!=sm)continue;
        int rvidx=n-sfidx-1;
        if(rvidx>i)cnt=max(cnt,i+sfidx+2);
    }
    cout<<cnt<<endl;
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