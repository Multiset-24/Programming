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
    if(k==1){
        int sm=0;
        for(int i=0;i<n;i++){
            int x=(i==0?a[n-1]:(i==n-1?a[0]:max(a[0],a[n-1])));
            sm=max(sm,a[i]+x);
        }
        cout<<sm<<endl;
        return;
    }
    k++;
    sort(a.begin(),a.end(),greater<int>());
    int sm=0;
    for(int i=0;i<k && i<n;i++){
        sm+=a[i];
    }
    cout<<sm<<endl;    
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