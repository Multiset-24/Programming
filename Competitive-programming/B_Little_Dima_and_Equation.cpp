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

int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
int sum(int a){
    int res=0;
    while(a){
        res+=(a%10);
        a/=10;
    }
    return res;
}
void jarvis()
{
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>ans;
    for(int i=0;i<=81;i++){
        int num=b*binpow(i,a)+c;
        if(num<0 || num>1e9)continue;
        if(sum(num)==i && num!=0)ans.push_back(num);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it<<" ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}