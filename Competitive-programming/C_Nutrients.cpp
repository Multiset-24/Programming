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

    vector<vector<int>>nv(n,vector<int>(m,0));
    vector<int>nul(m,0);
    for(int i=0;i<m;i++)cin>>nul[i];

    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cin>>nv[j][i];
        }
    }

    for(int j=0;j<m;j++){
        int c=0;
        for(int i=0;i<n;i++){
            c+=nv[i][j];
        }
        if(c<nul[j]){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
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