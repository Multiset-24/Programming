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
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'
int sumXorPair(vector<int>&num){
    int ans=0;
    int n=num.size();

    int bits[32]={0};

    for(int i=0;i<32;i++){
        for(int j=0;j<n;j++){
            int x=num[j];
            int bit=((x>>i)&1);
            if(bit)bits[i]++;
        }

    }

    for(int i=0;i<32;i++){
        int x=bits[i];

        ans+=((x)*(n-x)*(1LL<<i));
    }

    return ans;

}
void jarvis()
{
    int n;
    cin>>n;

    vector<int>num(n,0);

    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    cout<<sumXorPair(num)<<endl;
    
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