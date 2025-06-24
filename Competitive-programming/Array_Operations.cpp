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

    vector<int>nm(n,0);
    int maxm=0;
    
    for(int i=0;i<n;i++){
        cin>>nm[i];
        maxm=max(maxm,nm[i]);
    }
    if(n==1){
        cout<<nm[0]<<endl;
        return;
    }

    int addition=(n/2);

    map<int,set<int>>mp;

    for(int i=0;i<n;i++){
        mp[nm[i]].insert(i);
    }

    int ans=0;

    for(auto it:mp){
        int num=it.first;
        for(auto i:it.second){
            if(i%2==0){
                ans=max(ans,num+addition);
                break;
            }
            else{
                ans=max(ans,num+addition-1);
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
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}