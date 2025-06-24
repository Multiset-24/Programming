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
    uss case mai kya karenge jisme kuchh length<k tk consecutive uniques hai not >k 
    We can do binary search over length i to min(i+k,n-1) to find the index j such that num[j]-num[i]==j-i
*/
void jarvis()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    vector<pair<int,int>>fq;
    for(auto it:mp){
        int pv=(fq.size()?fq[fq.size()-1].second:0);
        fq.push_back({it.first,pv+it.second});
    }

    sort(fq.begin(),fq.end());
    int cnt=0;
    n=fq.size();
    auto search=[&](int lo,int hi){
        int st=lo;
        int ans=lo;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(fq[mid].first-fq[st].first==mid-st){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    };
    for(int i=0;i<n;i++){
        int idx=min(i+k-1,n-1);
        idx=search(i,idx);
        cnt=max(cnt,fq[idx].second-(i?fq[i-1].second:0));

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