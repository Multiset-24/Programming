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
    string a,b;
    cin>>a>>b;
    int anze=0,anzo=0,bnze=0,bnzo=0;
    for(int i=0;i<a.size();i++){
        if(i%2==0){
            if(a[i]=='0')anzo++;
            if(b[i]=='0')bnzo++;
        }
        else{
            if(a[i]=='0')anze++;
            if(b[i]=='0')bnze++;
        }
    }
    if(bnze>=(n+1)/2-anzo && bnzo>=(n/2)-anze){
        cout<<"YES"<<endl;
    }
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