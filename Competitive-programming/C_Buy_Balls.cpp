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
    int n,m;cin>>n>>m;

    vector<int>bl(n,0),wh(m,0);
    for(int i=0;i<n;i++)cin>>bl[i];
    for(int j=0;j<m;j++)cin>>wh[j];
    sort(bl.begin(),bl.end(),greater<int>());
    sort(wh.begin(),wh.end(),greater<int>());
    
    int i=0;
    int j=0;
    int ms=0;

    for(;i<n;i++){
        if(bl[i]>=0)ms+=bl[i];
        else break;
    }

    for(;j<m && j<i;j++){
        if(wh[j]>=0)ms+=wh[j];
        else break;
    }

    while(1){
        if(i<n && j<m && wh[j]+bl[i]>=0){
            ms+=(wh[j]+bl[i]);
            i++;
            j++;
        }
        else{
            break;
        }
    }
    cout<<ms<<endl;
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