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

int dig(int mid){
    int ans=0;

    while(mid>0){
        ans++;
        mid/=10;
    }

    return ans;
}
bool check(int a,int b,int x,int mid){
    return a*mid+b*dig(mid)<=x;
}
void jarvis()
{
    int a,b,x;
    cin>>a>>b>>x;

    int lo=0;
    int hi=1e9;

    int ans=0;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(a,b,x,mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
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