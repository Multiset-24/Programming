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
    int n;
    cin>>n;

    vector<int>num(n,0);
    for(auto &x:num)cin>>x;
    int minm=*min_element(num.begin(),num.end());
    if(minm!=0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<endl;
    }
    else if(num[0]!=0){
        cout<<2<<endl;
        cout<<2<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else if(num[n-1]!=0){
        cout<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else{
        cout<<3<<endl;
        cout<<3<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
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