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

#define box pair<pair<int,int>,int>
int fib[11]={1,2,3,5,8,13,21,34,55,89,144};
void jarvis()
{
    int n,m;
    cin>>n>>m;
    vector<box>b(m);
    int mx=fib[n-1];
    for(int i=0;i<m;i++){
        int l,w,h;
        cin>>l>>w>>h;
        b[i]={{l,w},h};
    }
    for(int i=0;i<m;i++){
        int l=b[i].first.first,w=b[i].first.second,h=b[i].second;
        if(l<mx || w<mx || h<mx){
            cout<<0;
            continue;
        }
        l-=mx;
        w-=mx;
        h-=mx;
        if(l<fib[n-2] && w<fib[n-2] && h<fib[n-2]){
            cout<<0;
        }
        else cout<<1;
    }
    cout<<endl;
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