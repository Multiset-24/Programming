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
// turn t=0 for tom and 1 for jerry
void jarvis()
{
    int n,k,sum=0;
    cin>>n>>k;
    vector<int>a(n);
    map<int,int>mp;
    for(auto &x:a){
        cin>>x;
        mp[x]++;
        sum+=x;
    }
    int maxm=*max_element(a.begin(),a.end());
    int minm=*min_element(a.begin(),a.end());
    int t=0;
    if(mp[maxm]==1){
        maxm--;
        sum--;
        t=!t;
    }
    if(maxm-minm>k){
        cout<<"Jerry"<<endl;
        return;
    }
    sum-=((n)*minm);
    if(sum%2!=0)t=!t;
    if(n%2==0){
        cout<<(t==1?"Tom":"Jerry")<<endl;
        return;
    }
    else{
        if(minm%2!=0){
            t=!t;
        }
        cout<<(t==1?"Tom":"Jerry")<<endl;
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