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

void jarvis()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<int>t_p;

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        t_p.push_back(x);
    }

    sort(t_p.begin(),t_p.end());

    while(q--){
        int x;
        cin>>x;
        if(x<t_p[0]){
            cout<<t_p[0]-1<<endl;
        }
        else if(x>t_p[m-1]){
            cout<<n-t_p[m-1]<<endl;
        }
        else{
            auto it=upper_bound(t_p.begin(),t_p.end(),x);

            int left=*(it-1);
            int right=*it;

            int midValue=(left+right)/2;

            cout<<min(abs(midValue-left),abs(midValue-right))<<endl;
        }
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
