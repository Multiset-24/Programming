#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define prin9t_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
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

    set<pair<int,int>>bullet_in_x;
    multiset<int>bullet_in_y;

    for(int i=0;i<n;i++){
        int x,ux;
        cin>>x>>ux;

        bullet_in_x.insert({x,ux});
    }

    for(int i=0;i<m;i++){
        int y,uy;
        cin>>y>>uy;

        bullet_in_y.insert(y*uy);
    }

    int cnt=0;

    for(auto it:bullet_in_x){
        int x=it.first;
        int ux=it.second;

        auto y=bullet_in_y.find(x*ux);
        if(y!=bullet_in_y.end())cnt++;

        if(y!=bullet_in_y.end())bullet_in_y.erase(y);
    }

    cout<<cnt<<endl;
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
