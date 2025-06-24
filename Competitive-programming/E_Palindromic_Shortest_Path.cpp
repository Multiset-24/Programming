#include <bits/stdc++.h>
using namespace std;
//this is mine code
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

const int INF=1e9;
typedef pair<int,int> state;
void jarvis()
{
    int n;
    cin>>n;

    vector<vector<char>>g(n,vector<char>(n,'-'));
    vector<vector<int>>dis(n,vector<int>(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        dis[i][i]=0;
        for(int j=0;j<n;j++){
            if(g[i][j]!='-'){
                dis[i][j]=min(1LL,dis[i][j]);
            }
        }
    }

    queue<state>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]!='-' && i!=j){
                q.push({i,j});
            }
        }
    }

    for(int i=0;i<n;i++){
        q.push({i,i});
    }

    while(!q.empty()){
        state t=q.front();
        q.pop();
        int u=t.first,v=t.second;

        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(g[x][u]!='-' && g[v][y]!='-' &&g[x][u]==g[v][y] && dis[x][y] >dis[u][v]+2){
                    dis[x][y]=dis[u][v]+2;
                    q.push({x,y});
                }
            }
        }        
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dis[i][j]!=INF){
                cout<<dis[i][j]<<" ";
            }
            else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
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