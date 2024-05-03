#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

vector<vector<pp>> gr;

void add_edge(int a, int b, int wt, bool bidir = true)
{
    gr[a].push_back({b, wt});
    if (bidir)
        gr[b].push_back({a, wt});
}
class cmp
{
    public:
    bool operator()(pp &p1, pp &p2)
    {
        return p1.second > p2.second;
    }
};

int prims(int src, int v, int e)
{
    // data-structures used

    priority_queue<pp, vector<pp>, cmp> pq;
    vector<int> parent(v,-1);
    vector<int> key(v, INT_MAX);
    unordered_set<int> visited;

    pq.push({src, 0});
    key[src]=0;
    int min_sum = 0;
    while (pq.size() > 0 && visited.size() < v)
    {
        pp curr = pq.top();
        pq.pop();

        if (visited.count(curr.first))
            continue;
        visited.insert(curr.first);
        min_sum += curr.second;

        for (auto neighbour : gr[curr.first])
        {
            if (!visited.count(neighbour.first) && key[neighbour.first] > neighbour.second)
            {
                parent[neighbour.first] = curr.first;
                key[neighbour.first] = neighbour.second;
                pq.push({neighbour.first, neighbour.second});
            }
        }
    }
    return min_sum;
}
int main()
{
    int v, e;
    cin >> v >> e;
    gr.clear();
    gr.resize(v);
    while (e--)
    {
        int a, b, wt;
        cin >> a >> b >> wt;

        add_edge(a, b, wt);
    }
    int src;
    cin >> src;
    cout << prims(src, v, e);
    return 0;
}