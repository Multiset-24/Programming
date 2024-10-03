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
int N=1000005;
void jarvis()
{
    int n,k,q;
    cin>>n>>k>>q;

    vector<int>arr(N,0);

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;

        arr[l]+=1;
        arr[r+1]-=1;
    }

    for(int i=0;i<N;i++){
        if(i)arr[i]+=arr[i-1];
    }

    for(int i=0;i<N;i++){
        arr[i]=(arr[i]>=k);
    }

    vector<int>ps(N,0);

    for(int i=0;i<N;i++){
        ps[i]=arr[i];
        if(i)ps[i]+=ps[i-1];
    }

    vector<int>print;
    while(q--){
        int l,r;
        cin>>l>>r;

        print.push_back(ps[r]-ps[l-1]);
    }

    for(auto it:print){
        cout<<it<<endl;
    }
    cout<<endl;
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
