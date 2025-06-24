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
    int n,m,k;
    cin>>n>>m>>k;

    int a[n];
    multiset<int>b;

    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b.insert(x);
    }

    sort(a,a+n);

    int cnt=0;

    for(int i=0;i<n;i++){
        
        auto it=b.lower_bound(a[i]-k);

        if(it==b.end())break;
        if((*it)>a[i]+k)continue;
        
        b.erase(it);

        cnt++;
    }
    
    cout<<cnt<<endl;
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