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
    vector<string>g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int r=0,c=0;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=0;j<m;j++)x^=(g[i][j]-'0');
        if(x)r++;
    }
    for(int i=0;i<m;i++){
        int x=0;
        for(int j=0;j<n;j++)x^=(g[j][i]-'0');
        if(x)c++;
    }
    cout<<min(r,c)+abs(r-c)<<endl;
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