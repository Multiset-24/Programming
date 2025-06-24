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
    vector<int>a;
    a.push_back(0);
    for(int i=1;i<n;i++){
        bool f=true;
        for(int j=0;j<31;j++){
            bool xo=(x&(1LL<<j));
            bool io=(i&(1LL<<j));
            if(io==1 && xo==0){
                f=false;
                break;
            }
        }
        if(f)a.push_back(i);
        else break;
    }
    while(a.size()<n)a.push_back(0);
    int z=0;
    for(auto it:a){
        z|=it;
    }
    if(z!=x){
        a.pop_back();
        a.push_back(x);
    }
    for(auto it:a)cout<<it<<" ";
    cout<<endl;
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