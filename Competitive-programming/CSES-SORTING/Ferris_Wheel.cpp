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
    int n,x;
    cin>>n>>x;

    int weights[n];
    multiset<int>w;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        weights[i]=x;
        w.insert(x);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(w.find(weights[i])!=w.end()){

            cnt++;
            auto y=w.find(weights[i]);
            if(y!=w.end())w.erase(y);
            auto it=w.upper_bound(x-weights[i]);

            if(it==w.begin()) continue;
            it--;

            w.erase(it);

        }
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