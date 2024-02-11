#include <bits/stdc++.h>
using namespace std;

//write a code to print all the paths from start to end of the index
#define mod 1000000007
vector<unordered_set<int>> graph;
int v; //no of  vertices
unordered_set<int> visited;
vector<vector<int>> result;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].insert(dest);

    if (bi_dir) {
        graph[dest].insert(src);
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";

        for (auto el : graph[i]) {
            cout << el << " , ";
        }
        cout << endl;
    }
}

void dfs(int start, int end, vector<int> &path) {
    if (start == end) {
        path.push_back(start);
        result.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(start);

    for (auto neighbour : graph[start]) {
        if (not visited.count(neighbour)) {
            path.push_back(neighbour);
            dfs(neighbour, end, path);
        }
        path.pop_back();
    }
}

void allpath(int start, int end) {
    vector<int> path;
    dfs(start, end, path);

    // Print all the paths
    for (const auto &p : result) {
        for (int node : p) {
            cout << node << " -> ";
        }
        cout << "end" << endl;
    }
}

int main() {
    cin >> v;
    graph.clear();
    graph.resize(v, unordered_set<int>());
    int e;
    cin >> e;
    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int start, end;
    cin >> start >> end;
    allpath(start, end);

    // display();
    return 0;
}
