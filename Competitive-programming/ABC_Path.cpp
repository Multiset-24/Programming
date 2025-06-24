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

typedef pair<int, int> state;
const int inf = 1e18;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void jarvis(int tcn, int n, int m)
{
    vector<vector<char>> g(n, vector<char>(m, '.'));
    vector<vector<int>> dis(n, vector<int>(m, inf));
    queue<state> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                q.push({i, j});
                dis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 8; i++)
        {
            int r = x + dx[i], c = y + dy[i];
            if (r < 0 || c < 0 || r >= n || c >= m || g[r][c] != g[x][y] + 1)
                continue;
            if (dis[r][c] > dis[x][y] + 1)
            {
                dis[r][c] = dis[x][y] + 1;
                q.push({r, c});
            }
        }
    }
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] != inf)
            {
                l = max(l, dis[i][j]);
            }
        }
    }
    cout << "Case " << tcn << ": " << l << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    int i = 1;
    while (true)
    {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;
        jarvis(i, h, w);
        i++;
    }
    return 0;
}