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
    vector<set<int>>g(n+1);
    vector<int>indg(n+1,0);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        s=" "+s;
        for(int j=1;j<=n;j++){
            if(s[j]=='1' && g[min(i,j)].count(max(i,j))==0){
                g[min(i,j)].insert(max(i,j));
                indg[max(i,j)]++;
            }
        }
    }
    multiset<int,greater<int>>ms;
    for(int i=1;i<=n;i++)if(indg[i]==0)ms.insert(i);
    vector<int>ans;
    while(!ms.empty()){
        int u=*ms.begin();
        ms.erase(ms.find(u));
        ans.push_back(u);
        for(auto v:g[u]){
            indg[v]--;
            if(indg[v]==0)ms.insert(v);
        }
    }
    for(auto it:ans)cout<<it<<" ";
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