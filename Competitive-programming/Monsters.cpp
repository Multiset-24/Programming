#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

const int inf = 1e18;
#define state pair<int, int>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
map<int, char> mp;

void jarvis()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m, '.'));
    vector<vector<int>> dm(n, vector<int>(m, inf)), da(n, vector<int>(m, inf));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    queue<state> qm, qa;
    state pa;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'M')
            {
                qm.push({i, j});
                dm[i][j] = 0;
            }
            if (g[i][j] == 'A')
            {
                pa = {i, j};
                qa.push({i, j});
                da[i][j] = 0;
            }
        }
    }
    if(pa.first==0 || pa.first==n-1 || pa.second==m-1 || pa.second==0){
        cout<<"YES"<<endl<<0<<endl;
        return;
    }
    function<void(queue<state> &, vector<vector<int>> &)> bfs = [&](queue<state> &q, vector<vector<int>> &dist) -> void
    {
        while (!q.empty())
        {
            state p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; i++)
            {
                int r = x + dx[i], c = y + dy[i];
                if (r < 0 || c < 0 || r >= n || c >= m || g[r][c] == '#')
                    continue;
                if (dist[r][c] > dist[x][y] + 1)
                {
                    dist[r][c] = dist[x][y] + 1;
                    q.push({r, c});
                }
            }
        }
    };
    bfs(qm, dm);
    bfs(qa, da);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    string s = "", sg = "";
    function<void(state)> dfs = [&](state curr) -> void
    {
        vis[curr.first][curr.second] = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = curr.first + dx[i], y = curr.second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#' || dm[x][y] <= da[x][y] || vis[x][y])
            continue;
            s.push_back(mp[i]);
            if (x == 0 || y == 0 || x == n - 1 || y == m - 1)sg = s;
            dfs({x, y});
            s.pop_back();
        }
    };
    dfs(pa);
    if (sg.size() == 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl<<sg.size()<<endl<<sg<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp[0] = 'D';
    mp[1] = 'U';
    mp[2] = 'R';
    mp[3] = 'L';
    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}