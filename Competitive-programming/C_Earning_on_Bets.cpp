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

int lcm(int a,int b){
    return a*b/(__gcd(a,b));
}
void jarvis()
{
    int n;
    cin>>n;
    vector<int>k(n);
    for(auto &x:k)cin>>x;
    int cd=k[0];
    for(int i=0;i<n;i++)cd=lcm(cd,k[i]);
    vector<int>ans(n);
    int s=0;
    for(int i=0;i<n;i++){
        ans[i]=cd/k[i];
        s+=ans[i];
    }
    if(s/cd>=1)cout<<-1<<endl;
    else{
        for(auto it:ans)cout<<it<<" ";
        cout<<endl;
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