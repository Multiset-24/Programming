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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a(m);
    vector<int>b;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b.push_back(x);
        a[i]={x/100,i};
    }
    sort(a.begin(),a.end());
    int i=0,j=m-1,gidx=1;
    int sc=0;
    while(gidx<=n){
        for(int l=0;l<6;l++)cout<<(l%2==0?b[a[i].second]:b[a[j].second])<<" \n"[l==5];
        if(gidx!=n)for(int l=0;l<6;l++)cout<<(l%2==0?b[a[j].second]:b[a[i].second])<<" \n"[l==5];
        i++;
        j--;
        gidx+=2;
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