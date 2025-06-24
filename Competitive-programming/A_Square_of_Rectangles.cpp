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
    int l1,b1,l2,b2,l3,b3;
    cin>>l3>>b3>>l2>>b2>>l1>>b1;
    bool c1=(l1+l2==l3)&&(b1==b2)&&(b1+b3==l3);
    bool c2=(b1+b2+b3==l3)&&(l3==l2)&&(l2==l1);
    bool c3=(l3+l2==b3)&&(l2==l1)&&(b1+b2==b3);
    bool c4=(l1+l2+l3==b3)&&(b1==b2)&&(b2==b3);
    if(c1||c2||c3||c4)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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