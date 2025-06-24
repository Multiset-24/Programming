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

typedef pair<int,int> state;
vector<string>g;
vector<vector<int>>dist;
vector<vector<state>>par;
const int INF=1e9;
int  dx[]={0,1,0,-1};
int  dy[]={1,0,-1,0};
int n,m;
string moves;

int bfs(state strt,state end){
    queue<state>q;//graph modelling
    dist[strt.first][strt.second]=0;
    q.push({strt.first,strt.second});

    while(!q.empty()){
        state s=q.front();
        q.pop();
        int x=s.first;
        int y=s.second;
        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];
            if(r>=0 && r<n && c>=0 && c<m && g[r][c]!='#'){
                if(dist[x][y]+1<dist[r][c]){
                    par[r][c]={x,y};
                    dist[r][c]=dist[x][y]+1;
                    q.push({r,c});
                }
            }
        }
    }
    return dist[end.first][end.second];
}

void get_moves(state curr,state next){
    int x1=curr.first;
    int y1=curr.second;
    int x2=next.first;
    int y2=next.second;

    if(x2-1==x1 && y1==y2)moves.push_back('U');
    else if(x2+1==x1 && y1==y2)moves.push_back('D');
    else if(y2+1==y1 && x1==x2)moves.push_back('R');
    else if(y2-1==y1 && x1==x2)moves.push_back('L');
}
void jarvis()
{
    cin>>n>>m;
    dist.resize(n,vector<int>(m,INF));
    par.resize(n,vector<state>(m,{-1,-1}));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        g.push_back(s);
    }

    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A'){
                st={i,j};
            }
            else if(g[i][j]=='B'){
                en={i,j};
            }
        }
    }

    if(bfs(st,en)==INF){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<bfs(st,en)<<endl;

    }
    state curr=en;
    while(curr.first!=-1){
        get_moves(curr,par[curr.first][curr.second]);
        curr=par[curr.first][curr.second];
    }
    reverse(moves.begin(),moves.end());y
    cout<<moves<<endl;
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