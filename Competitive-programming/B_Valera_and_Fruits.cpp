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
    int t,c;
    cin>>t>>c;
    vector<int>rf(3005,0);
    for(int i=0;i<t;i++){
        int x,y;cin>>x>>y;
        rf[x]+=y;
    }
    int ans=0;
    int prev=0;
    for(int i=1;i<3005;i++){
        if(rf[i]+prev<=c){
            ans+=(rf[i]+prev);
            prev=0;
        }
        else{
            if(prev<=c){
                ans+=prev;
                if(rf[i]>=(c-prev)){
                    ans+=(c-prev);
                    prev=rf[i]+prev-c;
                }                   
            }
            else{
                ans+=c;
                prev=rf[i];
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