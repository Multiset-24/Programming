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

int n,m,k;

bool check(int l) {
    int benches_per_row = m /(l+1); 
    int left=(m-(benches_per_row)*(l+1));
    int totalSeats = (benches_per_row) * n*l+n*left; 
    
    return totalSeats >= k; 
}

void jarvis()
{
    cin>>n>>m>>k;

    int lo=1,hi=m;
    int ans=1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(mid)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }

    cout<<ans<<endl;
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