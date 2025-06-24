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
    int n,k;
    cin>>n>>k;
    vector<int>nm(n,0);
    for(auto &x:nm)cin>>x;
    //case 1 [<=k,<=k,anything]
    int l=0;
    int l_idx=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(nm[i]<=k)l++;
        cnt++;
        if(l>=(cnt+1)/2){
            l_idx=i;
            if(cnt&1){
                if(i<n-1 && nm[i+1]>k)l_idx++;
            }
            break;
        }
    }
    cnt=0;
    int m=0;
    for(int i=l_idx+1;i<n-1 && l_idx!=-1;i++){
        if(nm[i]<=k)m++;
        cnt++;
        if(m>=(cnt+1)/2){
            cout<<"YES"<<endl;
            return;
        }
    }
    //case 2 [<=k,>k,<=k]
    l=0;
    l_idx=-1;
    cnt=0;
    for(int i=0;i<n;i++){
        if(nm[i]<=k)l++;
        cnt++;
        if(l>=(cnt+1)/2){
            l_idx=i;
            break;
        }
    }
    int r=0;
    cnt=0;
    for(int i=n-1;i>=l_idx+2 && l_idx!=-1;i--){
        if(nm[i]<=k)r++;
        cnt++;
        if(r>=(cnt+1)/2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cnt=0;
    r=0;
    int r_idx=-1;
    for(int i=n-1;i>=0;i--){
        if(nm[i]<=k)r++;
        cnt++;
        if(r>=(cnt+1)/2){
            r_idx=i;
            if(cnt&1){
                if(i>0 && nm[i-1]>k){
                    r_idx--;
                }
            }
            break;
        }
    }
    //case 3 [>k,<=k,<=k]
    m=0;
    cnt=0;
    for(int i=r_idx-1;i>=1 && r_idx!=-1;i--){
        if(nm[i]<=k)m++;
        cnt++;
        if(m>=(cnt+1)/2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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