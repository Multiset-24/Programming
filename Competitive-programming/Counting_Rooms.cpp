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
#define prin9t_2dvector(v)            \
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
int n, m;
typedef pair<int, int> state;
vector<vector<char>> g;
vector<vector<int>> vis;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void bfs(state node)
{
    queue<state> q;
    q.push(node);
    vis[node.first][node.second] = true;

    while (!q.empty())
    {
        state curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = x + dx[i];
            int c = y + dy[i];

            if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && g[r][c] != '#')
            {
                q.push({r, c});
                vis[r][c]=1;
            }
        }
    }
}
void jarvis()
{
    cin >> n >> m;

    vis.resize(n, vector<int>(m, 0));
    g.resize(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            // cout<<g[i][j]<<" ";
        }
        // cout<<endl;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] != '#' && !vis[i][j])
            {
                bfs({i, j});
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
