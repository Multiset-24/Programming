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
    vector<int>a(n+1,-1e18);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    int t=a[1];
    int lcnt=0,gcnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]>t)gcnt++;
        else lcnt++;
    }
    for(int i=1;i<=n;i++){
        if((a[i]==t && i==(n+1)/2)||gcnt+1==(n+1)/2){
            cout<<"YES"<<endl;
            return;
        }
    }
    if(lcnt==n || (gcnt<lcnt)){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
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