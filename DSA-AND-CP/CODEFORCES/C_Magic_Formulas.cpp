#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define prin9t_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

int xor_num[1000005];
void jarvis()
{   
    int n;
    cin>>n;

    vector<int>num;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        num.push_back(x);
    }
    memset(xor_num,0,sizeof(xor_num));

    for(int i=1;i<1000005;i++){
        xor_num[i]=i^xor_num[i-1];
    }

    int ans=num[0];

    for(int i=1;i<n;i++){
        int k=n/(i+1);
        if(k&1){
            ans=(ans^xor_num[(i)]);
        }

        int r=n%(i+1);

        if(r>0)ans=(ans^xor_num[r]);
        ans=(ans^num[i]);
    }

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
