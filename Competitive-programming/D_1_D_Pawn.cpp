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
    int n,p,q;
    cin>>n>>p>>q;

    vector<int>so(n+1,0);
    
    map<int,int>p2s;

    for(int i=1;i<=p;i++){
        int sq;cin>>sq;
        p2s[i]=sq;
        so[sq]=1;
    }

    while(q--){
        int pn;
        cin>>pn;

        if(p2s[pn]==n || so[p2s[pn]+1]==1){
            continue;
        }
        else{
            so[p2s[pn]]=0;
            so[p2s[pn]+1]=1;
            p2s[pn]=p2s[pn]+1;
        }
    }

    for(auto it:p2s)cout<<it.second<<" ";
    cout<<endl;
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