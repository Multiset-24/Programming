#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
bool vis[N];
vector<int> graph[N];

void dfs(int parent)
{

    for (auto child : graph[parent])
        vis[child] = true;
    {
        if (vis[child])
            continue;
        dfs(child);
    }

    return;
}
int main()
{

    int n;
    int e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <=n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}