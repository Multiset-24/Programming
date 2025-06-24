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
    vector<int>a(2*n);
    for(auto &x:a)cin>>x;
    queue<pair<int,int>>od,ev;
    for(int i=0;i<2*n;i++){
        if(a[i]&1)od.push({a[i],i+1});
        else ev.push({a[i],i+1});
    }
    if(od.size()%2!=0 && ev.size()!=0){
        od.pop();
        ev.pop();
    }
    else if(od.size()>=2){
        od.pop();
        od.pop();
    }
    else{
        ev.pop();
        ev.pop();
    }
    while(od.size()>=2){
        auto p1=od.front();
        od.pop();
        auto p2=od.front();
        od.pop();
        cout<<p1.second<<" "<<p2.second<<endl;
    }
    while(ev.size()>=2){
        auto p1=ev.front();
        ev.pop();
        auto p2=ev.front();
        ev.pop();
        cout<<p1.second<<" "<<p2.second<<endl;
    }
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