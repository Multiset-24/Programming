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
const int maxn=1e5+1;
vector<vector<int>>div(maxn);
void precompute(){
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            div[j].push_back(i);
        }
    }
}
void jarvis()
{
    int n,q;
    cin>>n>>q;
    vector<int>num(n,0);
    for(auto &x:num)cin>>x;
    map<int,vector<int>>d2i;
    for(int i=0;i<n;i++){
        d2i[num[i]].push_back(i);
    }
    while(q--){
        int k,l,r;
        cin>>k>>l>>r;
        
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}