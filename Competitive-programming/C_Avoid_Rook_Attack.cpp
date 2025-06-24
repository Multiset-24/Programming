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
    vector<string>board;

    for(int i=0;i<8;i++){
        string s;cin>>s;
        board.push_back(s);
    }

    vector<int>row(8,0);
    vector<int>col(8,0);

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='#'){
                row[i]=1;
                col[j]=1;
            }
        }
    }   
    int ans=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='.' && row[i]==0 && col[j]==0){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
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