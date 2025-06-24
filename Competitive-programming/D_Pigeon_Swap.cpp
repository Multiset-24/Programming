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
    int n,q;
    cin>>n>>q;

    int p2b[n+1],b2h[n+1],h2b[n+1];

    for(int i=1i<=n;i++){
        p2b[i]=i;b2h[i]=i;h2b[i]=i;
    }

    while(q--){
        int t;cin>>t;

        if(t==1){
            int a,b;
            cin>>a>>b;

            p2b[a]=h2b[b];
        }
        else if(t==2){
            int a,b;
            cin>>a>>b;
            
        }
        else{
            int p;
            cin>>a;
        }
    }
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