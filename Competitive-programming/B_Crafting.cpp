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
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int cnt=0,d=0,idx=-1;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            d=b[i]-a[i];
            idx=i;
            cnt++;
        }
    }
    if(idx==-1){
        cout<<"YES"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(idx!=i)a[i]-=d;
        else a[i]+=d;
    }
    if(cnt>=2){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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