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

vector<int> dijkstra(int src, int des, int n) {
    priority_queue<pp, vector<pp>, cmp> pq;
    vector<int> via(n, -1);
    vector<bool> visited(n, false);
    vector<int> mp(n, INT_MAX);
    vector<int> result(n); // Initialize result

    pq.push({0, src});
    mp[src] = 0;

    while (!pq.empty()) { // Removed `edgeCount < n &&` condition
        pp curr = pq.top();
        pq.pop();

        if (visited[curr.second]) continue;

        visited[curr.second] = true;
        result[curr.second] = curr.first; // Store result for the current node

        for (auto neighbour : gr[curr.second]) {
            if (!visited[neighbour.first] && mp[neighbour.first] > mp[curr.second] + neighbour.second) {
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second; // Fix update of mp vector
            }
        }
    }

    return result; // Return result vector
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

    int src, des;
    cin >> src >> des;

    vector<int> result = dijkstra(src, des, v); // Store the result from dijkstra function

    cout << result[des] << endl; // Print the distance to destination

    return 0;
}
