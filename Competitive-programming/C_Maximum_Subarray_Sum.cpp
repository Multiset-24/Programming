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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    const int ninf=-1e13;
    int p=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            a[i]=ninf;
            p=i;
        }
    }
    int cm=0,gm=ninf;
    for(int i=0;i<n;i++){
        cm=max(a[i],cm+a[i]);
        gm=max(cm,gm);
    }
    if(gm>k || (p==-1 && gm<k)){
        cout<<"No"<<endl;
        return;
    }
    if(p!=-1 && gm!=k){
        int pm=0,c=0;
        for(int i=p+1;i<n;i++){
            c+=a[i];
            pm=max(c,pm);
        }
        c=0;
        int sm=0;
        for(int i=p-1;i>=0;i--){
            c+=a[i];
            sm=max(c,sm);
        }
        a[p]=k-pm-sm;
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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