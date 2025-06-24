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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>seq(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>seq[i][j];
        }
    }
    vector<int>col(n+1,0);
    set<int>s={1,2,3};
    map<int,int>mp;
    for(int i=0;i<m;i++){
        if(i==0){
            int cc=1;
            for(int j=0;j<3;j++){
                col[seq[i][j]]=cc;
                mp[seq[i][j]]=cc;
                cc++;
            }
        }
        else{
            int cc=-1,cn=-1;
            for(int j=0;j<3;j++){
                if(mp.find(seq[i][j])!=mp.end()){
                    cc=mp[seq[i][j]];
                    cn=seq[i][j];
                    s.erase(cc);
                    break;
                }
            }
            for(int j=0;j<3;j++){
                if(seq[i][j]!=cn){
                    col[seq[i][j]]=*s.begin();
                    mp[seq[i][j]]=*s.begin();
                    s.erase(s.find(col[seq[i][j]]));
                }
            }
            s={1,2,3};
        }
    }    
    for(int i=1;i<=n;i++)cout<<col[i]<<" ";
    cout<<endl;
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