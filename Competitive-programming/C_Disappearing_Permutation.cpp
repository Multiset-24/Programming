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

    vector<int>num(n+1,0);
    vector<int>que(n+1,0);
    map<int,int>mp;

    for(int i=1;i<=n;i++){
        cin>>num[i];
        mp[num[i]]=i;
    }

    for(int i=1;i<=n;i++){
        cin>>que[i];
    }

    int ans=0;

    vector<int>vis(n+1,0);

    for(int i=1;i<=n;i++){
        int q=que[i];
        int curr=num[q];

        while(!vis[q] && num[q]!=que[i]){
            ans++;
            vis[q]=1;
            q=num[q];
        }
        if(!vis[q]){
            vis[q]=1;
            ans++;
        }

        cout<<ans<<" ";
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