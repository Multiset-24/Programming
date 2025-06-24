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
    vector<int>a(n);
    set<int>st;
    bool o=false,e=false;
    for(auto &x:a){
        cin>>x;
        if(x&1)o=true;
        else e=true;
        st.insert(x);
    }
    if(st.size()==1){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    if(o && e){
        for(int i=0;i<n;i++){
            cout<<((a[i]%2==0)?1:2)<<" ";
        }
        cout<<endl;
        return;
    }
    int idx=max_element(a.begin(),a.end())-a.begin();
    for(int i=0;i<n;i++){
        if(i!=idx)cout<<1<<" ";
        else cout<<2<<" ";
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