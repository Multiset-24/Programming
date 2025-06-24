#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long
#define ld long double
#define INF 1000000007
 
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v(6);
    vector<string> s(n);
    vector<string> temp_str = {"BG","BR","BY","GR","GY","RY"};
    vector<vector<int>> move = {{1,2,3,4},{0,2,3,5},{0,1,4,5},{0,4,1,5},{0,3,2,5},{1,3,2,4}};
    for(int i = 0;i<n;i++){
        // string s;
        cin>>s[i];
        if(s[i] == "BG"){
            v[0].push_back(i);
        }
        if(s[i] == "BR"){
            v[1].push_back(i);
        }
        if(s[i] == "BY"){
            v[2].push_back(i);
        }
        if(s[i] == "GR"){
            v[3].push_back(i);
        }
        if(s[i] == "GY"){
            v[4].push_back(i);
        }
        if(s[i] == "RY"){
            v[5].push_back(i);
        }
    }
    while(q--){
        int ans = INF;
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(l>r){
            swap(l,r);
        }
        string strl = s[l];
        string strr = s[r];
        if(strl[0] == strr[0] || strl[0] == strr[1] || strl[1] == strr[0] || strl[1] == strr[1]){
            cout<<(r-l)<<endl;
            continue;
        }
        int lidx,ridx;
        for(int i = 0;i<6;i++){
            if(strl == temp_str[i]){
                lidx = i;
            }
            if(strr == temp_str[i]){
                ridx = i;
            }
        }
        for(auto id : move[lidx]){
            auto temp = upper_bound(v[id].begin(), v[id].end(), l);
            int dx = temp - v[id].begin();
            if(dx < v[id].size()){
                ans = min(ans,abs(v[id][dx] - l) + abs(v[id][dx] - r));
            }
            if(dx>0){
                ans = min(ans,abs(v[id][dx-1] - l) + abs(v[id][dx-1] - r));
            }
        }
        for(auto id : move[ridx]){
            auto temp = upper_bound(v[id].begin(), v[id].end(), l);
            int dx = temp - v[id].begin();
            if(dx < v[id].size()){
                ans = min(ans,abs(v[id][dx] - l) + abs(v[id][dx] - r));
            }
            if(dx>0){
                ans = min(ans,abs(v[id][dx-1] - l) + abs(v[id][dx-1] - r));
            }
        }
        if(ans == INF){
            cout<<"-1"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
 
signed main()
// int32_t main()
// int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    // t=1;
    cin>>t;
    for(int i = 1;i<=t;i++){
        // cout<<i<<":";
        solve();
        // cout<<endl;
        // cout<<solve()<<endl;
    }
    return 0;
}