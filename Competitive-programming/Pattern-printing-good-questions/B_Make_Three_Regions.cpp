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
    vector<vector<char>>g(2,vector<char>(n,'.'));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cin>>g[i][j];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i-1>=0 && i+1<n && g[0][i]=='.' && g[1][i]=='.' && g[0][i-1]=='.' && g[0][i+1]=='.' && g[1][i-1]=='x' && g[1][i+1]=='x')cnt++;
    }
    for(int i=0;i<n;i++){
        if(i-1>=0 && i+1<n && g[1][i]=='.' && g[0][i]=='.' && g[1][i-1]=='.' && g[1][i+1]=='.' && g[0][i-1]=='x' && g[0][i+1]=='x')cnt++;
    }
    cout<<cnt<<endl;
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