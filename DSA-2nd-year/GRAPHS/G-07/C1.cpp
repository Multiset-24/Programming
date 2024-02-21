#include <bits/stdc++.h>
using namespace std;
// kahn's algorithm---topological sort
#define mod 1000000007

vector<unordered_set<int>> graph;
int v;
void add_edge(int a, int b, bool dir = false)
{
    graph[a].insert(b);
    if (!dir)
    {
        graph[b].insert(a);
    }
}

void topoBFS()
{
    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto neighbour : graph[i])
        {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    unordered_set<int> visited;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited.insert(i);
        }
    }

    while (q.size() > 0)
    {
        int node = q.front();
        cout << node << " ";

        q.pop();

        for (auto neighbour : graph[node])
        {
            if (not visited.count(neighbour))
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";

        for (auto el : graph[i])
        {
            cout << el << " , ";
        }
        cout << endl;
    }
}
int main()
{
    int e;
    cin >> v >> e;
    graph.clear();
    graph.resize(v, unordered_set<int>());

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        add_edge(a, b,true);
    }

    topoBFS();
    return 0;
}