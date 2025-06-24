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

int helper(int i,int T,int n,int k){
    int x=(i+1)*k+(i)*(i+1)/2;

    return abs(2*x-T);
}

int check(int idx , int n, int k,int T){
    if(helper(idx,T,n,k)>helper(idx-1,T,n,k) && helper(idx,T,n,k) <helper(idx+1,T,n,k)){
        return 1;
    }else{
        return 0;
    }
}
void jarvis()
{
    int n,k;

    cin>>n>>k;

    int lo=0;
    int hi=n-1;

    int ans=((n*k)+((n*(n-1))/2));
    int sum=((n*k)+((n*(n-1))/2));
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;


        if(check(mid,n,k,sum)){
            hi=mid-1;
            ans=hi;
        }
        else{
            lo=mid+1;
        }
    }

    cout<<helper(ans,sum,n,k)<<endl;
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
