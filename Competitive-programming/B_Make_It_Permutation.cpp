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
    int l=n;
    vector<pair<int,pair<int,int>>>vc;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            vc.push_back({i,{1,l}});
            if(l+1<=n)vc.push_back({i,{l+1,n}});
        }
        else{
            vc.push_back({i,{n-l+1,n}});
            if(n-l>=1)vc.push_back({i,{1,n-l}});
            l--;
        }
    }
    cout<<vc.size()<<endl;
    for(auto p:vc){
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    }
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