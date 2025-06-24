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

int n;
vector<int>a;
bool check(int l,int r,int ma,int mi){
    if((a[l]!=ma && a[r]!=mi) && (a[l]!=mi && a[r]!=ma))return true;
    return false;
}
void jarvis()
{
    cin>>n;
    a.assign(n,0);
    for(auto &x:a)cin>>x;
    int l=0,r=n-1;
    int maxm=n,minm=1;
    while(l<=r){
        if(check(l,r,maxm,minm)){
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
        else if(a[l]==maxm){
            l++;
            maxm--;
        }
        else if(a[r]==maxm){
            r--;
            maxm--;
        }
        else if(a[l]==minm){
            l++;
            minm++;
        }
        else if(a[r]==minm){
            r--;
            minm++;
        }
    }
    cout<<-1<<endl;
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