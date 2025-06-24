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
    cin >> n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    int sgtn=1;//segment number hai ye
    set<int>cst,gst;//current set , global set
    gst.insert(a[0]);
    cst.insert(a[0]);
    int i=1;
    while(i<n){
        while(i<n && !cst.empty()){
            if(cst.count(a[i]))cst.erase(a[i]);
            gst.insert(a[i]);
            i++;
        }
        if(!cst.empty())break;
        sgtn++;
        cst=gst;
    }
    cout<<sgtn<<endl;
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