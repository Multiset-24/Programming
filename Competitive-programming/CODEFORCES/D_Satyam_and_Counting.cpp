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
    int n;
    cin>>n;

    int NOT=0;

    set<pair<int,int>>points;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        points.insert({x,y});
    }
    set<pair<int,int>>vis;
    for(auto it:points){
        int x=it.first;
        int y=it.second;

        if(points.find({x, 1 - y}) != points.end() && vis.find({x,1-y})==vis.end()){
            NOT += (n - 2);
            vis.insert({x,1-y});
        }

        if(points.find({x - 1, 1 - y}) != points.end() && points.find({x + 1, 1 - y}) != points.end()) NOT++;
        vis.insert({x,y});
    }

    cout<<NOT<<endl;
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
