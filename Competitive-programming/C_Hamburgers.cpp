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

string s;
int pb,ps,pc,br,so,ch,t;
map<char,int>mp;
int cb,cs,cc;
bool check(int x){
    int breq=x*mp['B'];
    int sreq=x*mp['S'];
    int creq=x*mp['C'];
    int ct=t;
    if(breq>br){
        ct-=((breq-br)*pb);
        if(ct<0)return false;
    }if(sreq>so){
        ct-=((sreq-so)*ps);
        if(ct<0)return false;
    }if(creq>ch){
        ct-=((creq-ch)*pc);
        if(ct<0)return false;
    }
    return true;
}
void jarvis()
{
    cin>>s;
    cin>>br>>so>>ch>>pb>>ps>>pc>>t;
    for(auto &x:s)mp[x]++;
    cb=pb*mp['B'];
    cs=ps*mp['S'];
    cc=pc*mp['C'];
    int lo=1,hi=(t+max({br,so,ch}));
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)){
            lo=mid+1;
            ans=mid;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
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