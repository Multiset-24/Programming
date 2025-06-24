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
    int n,m,k;
    cin>>n>>m>>k;
    if(n==1){//ye n==1 ka edge case hai jisme edges 0 honi chahiy and k-1 ki value should be greater than 0 honi chahiy
        if(m==0 && k>1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(k==3 && m==(n*(n-1))/2)cout<<"YES"<<endl;//when the graph needed is a complete graph where all are at a distance of 2 from each other 
    else if(m>=n-1 && m<=((n*(n-1))/2) && k-1>2)cout<<"YES"<<endl;//baaki cases jisme m belongs to [n-1,n(n-1)/2] and in sb graph ke diameters ki range [2,n-1] hogi mtln ki agr k-1>2 then hum koi sa bhi graph bna skte hai depending on diamter requirement
    else cout<<"NO"<<endl;//baaki ke cases mai possible nhi hai aesa graph bnana
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