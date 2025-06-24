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
// #define endl '\n'

void jarvis()
{
    int lo=1,hi=999;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        cout<<"? "<<mid<<" "<<mid<<endl;
        cout.flush();
        int ma=mid*mid;
        int ga;
        cin>>ga;

        if(ga>ma){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
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