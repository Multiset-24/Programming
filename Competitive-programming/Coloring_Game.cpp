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
    Constraints hai sum of red coloring >blue coloring
    Question change -> # of ways to select the edges of a traingle such that no edge left has value > sum of selected edges

    approach -> isko hum 2 pointer + sorting se kar skte hai like pehle sort karo to isse do condition match ho jaygi i=0 and j=k-1 shuruwaat mai thus aj>ak+ai , ak+aj>ai , teesri condition ke liy loop lagana padega 
*/
void jarvis()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    int cnt=0;
    for(int k=n-1;k>=2;k--){
        int lo=0,hi=k-1;
        while(lo<=hi){
            if(a[lo]+a[hi]>a[k]){
                int idx=upper_bound(a.begin(),a.end(),a[n-1]-(a[hi]+a[k]))-a.begin();
                if(a[n-1]-(a[hi]+a[k])<0)idx=lo;
                if(idx<=hi && idx>=lo){
                    cnt+=(hi-idx);
                }
                hi--;
            }
            else{
                lo++;
            }
        }
    }
    cout<<cnt<<endl;
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