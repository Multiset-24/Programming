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
    int n,k;
    cin>>n>>k;
    vector<int>l(n,0),r(n,0);
    for(auto &x:l)cin>>x;
    for(auto &y:r)cin>>y;
    int sm=0;
    multiset<int>ms;
    for(int i=0;i<n;i++){
        sm+=max(l[i],r[i]);
        ms.insert(min(l[i],r[i]));
    }
    int i=0;
    while(i<k-1){
        int x=*ms.rbegin();
        sm+=(*ms.rbegin());
        ms.erase(ms.find(x));
        i++;
    }
    cout<<sm+1<<endl;
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