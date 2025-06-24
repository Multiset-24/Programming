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
    string s;
    cin>>s;
    int n=s.size();
    auto f=[&](int i,int j){
        while(j>i){
            s[j]--;
            swap(s[j],s[j-1]);
            j--;
        }
    };
    for(int i=0;i<n;i++){
        int pos=i;
        char cm=s[i];
        for(int j=i;j<i+9 && j<n;j++){
            if(s[j]-(j-i)>cm){
                cm=s[j]-(j-i);
                pos=j;
            }
        }
        f(i,pos);
    }
    cout<<s<<endl;
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