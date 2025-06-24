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
/*
    possible tb nhi hoga jb b and c dono hi 0 ho jaaye .
    To minimise operation hume har ek operation mai nya [0...n-1] milega thus upper bound n-1 hoga vhi agr hum calculate karle ki array a mai kitne integers already 0 to n-1 ke beech hai then answer n-(already present hoga) ye tbhi hoga jb b and c dono 0 na ho

    jb b 0 hoga then sbhi elements barabar honge-> 3 3 3 3 3 ispe simple observation hai agr n-1<=c+1 hai to possible hai with n-1 operation verna to nhi hai simple 
*/
void jarvis()
{
    int n,b,c;
    cin>>n>>b>>c;
    if(b==0 && c==0 && n>2)cout<<-1<<endl;
    else if(b==0 && c==0){
        if(n==1)cout<<0<<endl;
        else cout<<1<<endl;
    }
    else if(b==0){
        if(n-1<c)cout<<n<<endl;
        else if(n-1==c || n-2==c)cout<<n-1<<endl;
        else cout<<-1<<endl;
    }
    else{
        int prst=max(0LL,(n-1-c+b)/b);
        cout<<n-prst<<endl;
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