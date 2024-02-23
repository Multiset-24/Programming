#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

vector<list<pp>> gr;

void add_edge(int u, int v, int wt, bool bidir = true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});
    }
}

class cmp {
public:
    bool operator()(pp p1, pp p2) {
        return p1.first > p2.first;
    }
};

ll prims(int src, int n) {
    priority_queue<pp, vector<pp>, cmp> pq;
    vector<int> par(n, -1);
    vector<bool> visited(n, false);
    vector<int> mp(n, INT_MAX);
    pq.push({0, src});
    mp[src] = 0;

    int edgeCount = 0;
    ll result = 0;

    while (edgeCount < n && pq.size() > 0) {
        pp curr = pq.top();
        pq.pop();

        if (visited[curr.second]) continue;

        visited[curr.second] = true;
        edgeCount++;
        result += curr.first;

        for (auto neighbour : gr[curr.second]) {
            if (!visited[neighbour.first] && mp[neighbour.first] > neighbour.second) {
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }

    return result;
}

int main() {
    int v, e;
    cin >> v >> e;

    gr.resize(v);
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;

        add_edge(a, b, c);
    }

    int src;
    cin >> src;

    cout << prims(src, v) << endl;

    return 0;
}
