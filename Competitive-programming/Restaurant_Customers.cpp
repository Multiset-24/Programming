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

    vector<pair<int,int>>events;

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;

        events.push_back({l,+1});
        events.push_back({r,-1});
    }

    sort(events.begin(),events.end());

    int cnt=0;
    int max_cnt=0;

    for(int i=0;i<2*n;i++){
        cnt+=events[i].second;
        max_cnt=max(cnt,max_cnt);
    }

    cout<<max_cnt<<endl;
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