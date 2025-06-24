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
Approach-> so basically we try to simulate the binary search over range l,r , and 

*/
void jarvis()
{
    int n,q;
    cin>>n>>q;
    vector<int>num(n,0);
    vector<int>inv(n+1,0);
    for(int i=0;i<n;i++){
        cin>>num[i];
        inv[num[i]]=i;
    }
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        int su=0,sn=0,bu=0,bn=0;
        int x=k;
        k=inv[k];
        bool f=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(k==m){
                f=1;
                break;
            }
            else if(m>k){
                r=m-1;
                if(num[m]>x)bu++;
                else if(num[m]<x)bn++;
            }
            else{
                l=m+1;
                if(num[m]<x)su++;
                else if(num[m]>x)sn++;
            }
        }
        int op=-1;
        if(f){
            int t=sn+bn;
            if(sn>bn){
                int lo=sn-bn;
                int p=x-1-su;
                if(p>=sn){
                    op=t+lo;
                }
            }
            else{
                int lo=bn-sn;
                int p=n-x-bu;
                if(p>=bn){
                    op=t+lo;
                }
            }
        }
        cout<<op<<" ";
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