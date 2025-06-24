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

    vector<int>num(n,0);

    for(int i=0;i<n;i++)cin>>num[i];

    map<int,int>mp;
    mp[0]+=3;
    mp[1]++;
    mp[2]+=2;
    mp[3]++;
    mp[5]++;

    for(int i=0;i<n;i++){
        if(mp.find(num[i])!=mp.end()){
            mp[num[i]]--;
            if(mp[num[i]]==0){
                mp.erase(num[i]);
            }
            if(mp.empty()){
                cout<<i+1<<endl;
                return;
            }
        }
    }

    cout<<0<<endl;
    return;
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