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
    for(auto &x:a)cin>>x;
    set<int>st;
    int rmx=0;
    map<int,set<int>>mp;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
        mp[a[i]].insert(i);
    }
    for(auto x:st){
        if(x==rmx)rmx++;
    }
    int lmx=0;
    st.clear();
    for(int i=0;i<n-1;i++){
        if(a[i]==lmx){
            while(st.count(lmx+1)){
                lmx++;
            }
            lmx++;
        }
        if(a[i]<rmx){
            auto it=mp[a[i]].upper_bound(i);
            if(it==mp[a[i]].end()){
                rmx=a[i];
            }
        }
        if(lmx==rmx){
            cout<<2<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }
        st.insert(a[i]);
    }
    cout<<-1<<endl;
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