#include <bits/stdc++.h>
using namespace std;

// write a code to print breadth first traversal for the graph

#define mod 1000000007
vector<unordered_set<int>> graph;
int v; // no of  vertices
unordered_set<int> visited;
vector<int> result;

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

void bfs(int start)
{
    queue<int> q;

    q.push(start);
    visited.insert(start);
    while (q.size() > 0)
    {
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for (auto neighbour : graph[temp])
        {
            if (not visited.count(neighbour))
            {
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}



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
    
    int start;
    cin>>start;
    bfs(start);
    return 0;
}
