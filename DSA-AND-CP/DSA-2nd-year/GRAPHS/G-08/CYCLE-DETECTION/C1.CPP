#include <bits/stdc++.h>
using namespace std;
//search for cycle in a graph using dfs


class Solution {
  public:
    
    // Function to detect cycle in an undirected graph.
    vector<vector<int>> graph; // Correct declaration of graph

    Solution() {} // Constructor

    // Function to detect cycle in an undirected graph using DFS.
    bool dfs(int ele, int parent, vector<bool>& visited) {
        visited[ele] = true;
        for (auto neighbour : graph[ele]) {
            if (neighbour == parent) continue;
            if (!visited[neighbour]) return dfs(neighbour, ele, visited);
            else if (visited[neighbour] && neighbour != parent) return true;
        }
        return false; // If no cycle detected
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        graph.assign(V, vector<int>()); // Initialize graph
        for (int i = 0; i < V; i++) {
            for (auto ele : adj[i]) {
                graph[i].push_back(ele); // Constructing the graph
            }
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited)) return true; // If cycle detected, return true
            }
        }

        return false; // If no cycle detected in any component
    }
};
#define mod 1000000007

int main() {
 
    return 0;
}