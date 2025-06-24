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
const int maxm=1e7+10;

int prime[maxm];
int prime_prefix[maxm];

int f(){
    for(int i=0;i<maxm;i++)prime[i]=1;

    prime[0]=prime[1]=0;

    for(int i=2;i<maxm;i++){
        if(prime[i]){
            for(int j=i*i;j<maxm;j+=i){
                prime[j]=0;
            }
        }
    }

    for(int i=2;i<maxm;i++){
        prime_prefix[i]=prime[i]+prime_prefix[i-1];
    }
}


void jarvis()
{
    int n;
    cin>>n;
    int ans=0;

    for(int a=1;a<=n;a++){
        ans+=(prime_prefix[n/a]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f();
    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}