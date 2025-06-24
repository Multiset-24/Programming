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
    vector<vector<int>>g(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    set<int>st;
    for(int i=1;i<=2*n;i++){
        st.insert(i);
    }
    vector<int>p(2*n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i+j]=g[i][j];
            st.erase(g[i][j]);
        }
    }
    for(int i=1;i<=2*n;i++){
        if(p[i]==0){
            p[i]=*st.begin();
            st.erase(p[i]);
        }
    }
    for(int i=1;i<=2*n;i++){
       cout<<p[i]<<" ";
    }
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