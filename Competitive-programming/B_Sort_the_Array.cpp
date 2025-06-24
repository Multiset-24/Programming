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

const int inf=1e10;
void jarvis()
{
    int n;
    cin>>n;
    vector<int>num;
    num.push_back(-inf);
    for(int i=0;i<n;i++){
        int x;cin>>x;num.push_back(x);
    }
    num.push_back(inf);
    int l=1,r=1;
    bool f=false;
    for(int i=0;i<=n;i++){
        if(num[i]>num[i+1]){
            l=i;
            while(num[i]>num[i+1]){
                i++;
            }
            r=i;
            i--;
            f=true;
        }
    }
    reverse(num.begin()+l,num.begin()+r+1);
    for(int i=1;i<=n;i++){
        if(num[i]>num[i+1]){
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;
    cout<<l<<" "<<r<<endl;
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