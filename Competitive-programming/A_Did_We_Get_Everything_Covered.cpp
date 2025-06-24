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
    Hum isme 2 pointers use karenge to find ki string s mai km se km n groups ho jinme a....a+k-1 tk ke sequences ho taaki hume saari possible strings mil jaaye jo first k alphabets ka use karke bn skti hai baaki agr ek bhi group missing hai to last group ka element jo missing hai usko hum har group se ek ek lene ke baad n-cnt times uss character ko uss string mai append kar skte hai 
*/
void jarvis()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;
    int cnt=0;
    set<char>st;
    string ans="";
    for(int i=0;i<m;){
        int msk=0;
        int j=i;
        while(j<m && msk<((1LL<<k)-1)){
            if(s[j]<='a'+k-1){
                st.insert(s[j]);
                msk|=(1LL<<(s[j]-'a'));
            }
            j++;
        }
        if(msk==((1<<k)-1)){
            cnt++;
            ans+=s[j-1];
            st.clear();
        }
        i=j;
    }
    if(cnt<n){
        cout<<"NO"<<endl;
        char mis='a';
        while(st.find(mis)!=st.end())mis++;
        for(int i=0;i<n-cnt;i++)ans+=mis;
        cout<<ans<<endl;
    }
    else cout<<"YES"<<endl;
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