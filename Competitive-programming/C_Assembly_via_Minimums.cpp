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

const int inf=1e9;
void jarvis()
{
    int n;
    cin>>n;
    int m=(n*(n-1))/2;
    map<int,int>b;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b[x]++;
    }
    vector<int>a;
    for(auto it:b){
        int k=it.second;
        while(k>0){
            k-=(n-a.size()-1);
            a.push_back(it.first);
        }
    }
    while(a.size()<n){
        a.push_back(inf);
    }
    for(auto x:a){
        cout<<x<<" ";
    }
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