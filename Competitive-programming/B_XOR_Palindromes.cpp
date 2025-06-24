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
    string s;
    cin>>s;
    int gpc=0,bpc=0;//ye hai good pair count,and bad pair count 
    for(int i=0;i<=n/2;i++){
        if(i>n-i-1)continue;
        if(s[i]!=s[n-i-1])bpc++;
        else gpc++;
    }
    auto check=[&](int x){
        if((x%2==0 && x<=2*gpc) || (n%2!=0 && (x-1)%2==0 && x-1<=2*gpc))return true;//yaha hum pair wise check kar rhe hai agr aesa case hai jb bche hue one's ka use karke hum good pairs mai adjust karskte hai then ok agr nhi to ek odd specific case hai jisme hum 1 minus karte hai then baaki x-1 ko check karte hai kyunki ab vo even hoga 
        else return false;
    };
    if(n&1)gpc--;
    for(int i=0;i<n+1;i++){
        if(i>=bpc){
            int x=i-bpc;
            if(check(x))cout<<1;
            else cout<<0;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;
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