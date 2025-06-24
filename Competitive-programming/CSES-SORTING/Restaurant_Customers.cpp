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

    vector<pair<int,int>>customer;
    multiset<int>ending;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        customer.push_back({x,y});
    }

    sort(customer.begin(),customer.end());

    int cnt=0;
    int max_cnt=0;
    for(int i=0;i<n;i++){
        int strt=customer[i].first;
        int end=customer[i].second;

        if(strt<=*(ending.begin()) || ending.size()==0){
            ending.insert(end);
            cnt++;
        }
        else{
            while(ending.size()>0 && *ending.begin()<=strt){
                auto it=ending.begin();
                ending.erase(it);
            }
            ending.insert(end);
            cnt=ending.size();
        }
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