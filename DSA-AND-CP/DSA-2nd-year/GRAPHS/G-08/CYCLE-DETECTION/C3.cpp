#include <bits/stdc++.h>
using namespace std;
/*
---------cycle detecion using bfs approach for an undirected graph--------------
*/
int n;
#define mod 1000000007
vector<unordered_set<int>> graph;
vector<int> parent;

void add_edge(int a, int b, bool dir = false)
{
    graph[a].insert(b);
    if (!dir)
        graph[b].insert(a);
}

bool bfs(int src)
{
    unordered_set<int>vis;
    queue<int> qu;
    vector<int> par(n, -1);
    qu.push(src);

    while (not qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        for (auto neighbour : graph[curr])
        {
            if (vis.count(neighbour) and par[curr] != neighbour)
                return true;
            if (!vis.count(neighbour))
            {
                vis.insert(neighbour);
                par[neighbour] = curr;
                qu.push(neighbour);
            }
        }
    }

    return false;
}

int main()
{
    cin >> n;

    graph.clear();
    graph.resize(n, unordered_set<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int a, b;
        cin>>a>>b;
        add_edge(a, b);
    }
    int start;
    cin >> start;
    if (bfs(start))
        cout << "cycle detected";
    return 0;
}