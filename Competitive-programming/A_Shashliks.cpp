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
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    if(x>y){
        int c1=0;
        if(k>=b)c1=(k-b+y)/y;
        k-=(c1*y);
        if(k>=b){
            k-=y;
            c1++;
        }
        int c2=0;
        if(k>=a)c2+=(k-a+x)/x;
        k-=(c2*x);
        if(k>=a){
            k-=x;
            c2++;
        }
        cout<<c1+c2<<endl;
    }
    else{
        int c1=0;
        if(k>=a)c1=(k-a+x)/x;
        k-=(c1*x);
        if(k>=a){
            k-=x;
            c1++;
        }
        int c2=0;
        if(k>=b)c2+=(k-b+y)/y;
        k-=(c2*y);
        if(k>=b){
            k-=y;
            c2++;
        }
        cout<<c1+c2<<endl;
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