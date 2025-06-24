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

    vector<vector<int>>photos(m,vector<int>(n,0));
    vector<vector<int>>pairs(n+1,vector<int>(n+1,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>photos[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            pairs[photos[i][j]][photos[i][j+1]]=1;
            pairs[photos[i][j+1]][photos[i][j]]=1;
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>j && pairs[i][j]==0){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
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