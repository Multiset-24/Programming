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

    vector<int>num(n,0);
    map<int,int>left,right;

    for(int i=0;i<n;i++){
        cin>>num[i];
        right[num[i]]++;
    }

    right[num[0]]--;
    if(right[num[0]]==0)right.erase(num[0]);
    left[num[0]]++;
    int ans=0;

    for(int i=1;i<n;i++){
        ans=max(ans,1LL*(left.size()+right.size()));
        left[num[i]]++;
        right[num[i]]--;
        if(right[num[i]]==0){
            right.erase(num[i]);
        }
    }
    ans=max(ans,1LL*(left.size()+right.size()));
    
    cout<<ans<<endl;
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