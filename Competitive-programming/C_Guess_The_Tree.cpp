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
    function<int(int ,int)>f=[&](int u,int v)->int{
        cout<<"? "<<u<<" "<<v<<endl;
        int q;
        cin>>q;
        if(q==u)return q;
        else return f(q,v);
    };
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++){
        if(i==3) continue;
        int p=f(3,i);
        ans.push_back({p,i});
    }
    cout<<"! ";
    for(auto v:ans)cout<<v.first<<" "<<v.second<<" ";
    cout<<endl;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}