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
    int n,m;
    cin>>n>>m;
    vector<int>num(n,0);
    for(auto &x:num)cin>>x;
    vector<int>sz(n+1,0);
    set<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.find(num[i])==st.end()){
            st.insert(num[i]);
        }
        sz[i]=st.size();
    }
    while(m--){
        int l;cin>>l;
        l--;
        cout<<sz[l]<<endl;
    }
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