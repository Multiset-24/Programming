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
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>>pt(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>pt[i][j];
        }
    }
    vector<vector<int>>pn(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        sort(pt[i].begin(),pt[i].end());
        pn[i][0]=pt[i][0];
        for(int j=1;j<m;j++){
            pn[i][j]=pt[i][j]+pn[i][j-1];
        }
    }
    vector<pair<int,int>>osc(n);
    for(int i=0;i<n;i++){
        int tl=h;
        int pne=0;
        int cnt=0;
        for(int j=0;j<m;j++){
            if(tl>=pt[i][j]){
                tl-=pt[i][j];
                pne+=pn[i][j];
                cnt++;
            }
        }
        osc[i]={cnt,pne};
    }
    int cnt=1;
    for(int i=1;i<n;i++){
        if(osc[i].first>osc[0].first || (osc[i].first==osc[0].first && osc[i].second<osc[0].second))cnt++;
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