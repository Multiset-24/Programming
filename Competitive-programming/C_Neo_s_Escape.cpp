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
    int cnt=0;
    a.erase(unique(a.begin(),a.end()),a.end());
    n=a.size();
    if(n==1)cnt=1;
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i+1] && a[i]>a[i-1])cnt++;
    }
    if(n==2){
        cout<<1<<endl;
        return;
    }
    if(n>=3){
        if(a[0]>a[1])cnt++;
        if(a[n-1]>a[n-2])cnt++;
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