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

class cmp{
    public:

    operator()(pair<int,int>&a,pair<int,int>&b){
        int x=a.first;
        int y=b.first;

        if(x==y) return a.second>b.second;
        return x<y;
    }
};
void jarvis()
{
    int n,k;
    cin>>n>>k;

    vector<int>num;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        num.push_back(x);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

    int i=0;
    int j=0;

    while(j<n){
        //do work
        pq.push({num[j],j});
        if(j-i+1>k){
            //do work
            i++;
            while(pq.top().second<i){
                pq.pop();
            }
        }
        //do work
        if(j-i+1==k)cout<<pq.top().first<<" ";
        j++;
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
