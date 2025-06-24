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

    vector<int>p(n,0);

    for(int i=0;i<s.size();i++){
        p[i]=(s[i]-'0');
        if(i)p[i]+=p[i-1];
    }

    vector<int>arr;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')arr.push_back(i);
    }

    int mid=arr[arr.size()/2];

    int minS=0;

    for(int i=0;i<s.size();i++){
        int l=0;
        if(s[i]=='0')continue;
        if(i<mid){
            l=mid-i+1;
            minS+=(l-(p[mid]-(i>0?p[i-1]:0)));
        }
        else if(i>mid){
            l=i-mid+1;
            minS+=(l-(p[i]-(mid==0?0:p[mid-1])));
        } 
    }

    cout<<minS<<endl;
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