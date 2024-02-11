#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<int>> graph;
int v; // no of  vertices
// unordered_set<int> visited;
void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].insert(dest);

    if (bi_dir)
    {
        graph[dest].insert(src);
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
// find  the number of connected  coomponents in the graph using dfs or bfs
// NCC=no of connected components
unordered_set<int>visited;
void dfs(int idx)
{
    visited.insert(idx);

    for (auto ele : graph[idx])
    {
        if (not visited.count(ele))
        {
            dfs(ele);
        }
    }
}

int NCC(int count)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (not visited.count(i) )
        {
            dfs(i);
            count++;
        }
    }
    return count;
}
#define mod 1000000007

int main()
{
    cin >> v;
    graph.clear();
    graph.resize(v, unordered_set<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int count = 0;
    cout << NCC(count);
    return 0;
}