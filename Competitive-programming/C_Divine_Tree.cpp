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
#define print_map(m)    { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v){ cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif

#define endl '\n'

void jarvis()
{
    int n, m;
    cin >> n >> m;
    if (m < n || m > (n * (n + 1) / 2)) {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n + 1, 1);
    int rem = m - n;
    for (int i = n; i >= 1 && rem > 0; --i) {
        int add = min(rem, i - 1LL);
        a[i] += add;
        rem -= add;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    vector<vector<int>> g(n + 1);
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    int mv=*max_element(a.begin(),a.end());
    mp[mv]--;
    if(mp[mv]==0)mp.erase(mv);
    st.erase(mv);
    vector<int>par(n+1,0);
    for(auto it:mp){
        par[it.first]=mv;
        g[mv].push_back(it.first);
        st.erase(it.first);
    }
    for(auto it:mp){
        int f=it.second;
        if(st.size()==0)break;
        while(f--){
            par[*st.begin()]=(g[it.first].size()>0?g[it.first].back():it.first);
            g[it.first].push_back(*st.begin());
            st.erase(*st.begin());
            if(st.size()==0)break;
        }
    }
    cout<<mv<<endl;
    for(int i=1;i<=n;i++){
        if(g[i].size()==0)continue;
        for(int j=0;j<g[i].size();j++){
            if(par[g[i][j]]!=g[i][j])cout<<par[g[i][j]]<<" "<<g[i][j]<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
