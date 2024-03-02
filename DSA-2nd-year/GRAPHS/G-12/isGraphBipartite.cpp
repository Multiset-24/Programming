#include <bits/stdc++.h>
using namespace std;
// leetcode-785 : https://leetcode.com/problems/is-graph-bipartite/
// A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

// We can use a depth first search (DFS) algorithm to color the nodes of the graph. We can start by coloring the first node red, and then coloring all of it's neighbors blue, then their neighbors red, and so on. If we ever find a neighbor that is already colored and it has the same color as the current node, then our coloring was impossible.

// Algorithm:
// We will use a color array to store the color of each node. The colors will be either 0, 1, or -1. The value of -1 will represent that the node has not been colored yet. The colors 0 and 1 will represent the two different colors of the graph.
// We will use a queue to store the nodes that we need to color and the color that we will use to color them.
// We will iterate through all the nodes of the graph, and for each node, we will color it and all of it's neighbors. If we ever find a neighbor that is already colored and it has the same color as the current node, then our coloring was impossible.
// If we have colored all the nodes of the graph and we never found a conflict, then the graph is bipartite.
#define mod 1000000007
#define ll long long
typedef pair<int,int> pp;
class Solution {
public:

    bool bfs(vector<vector<int>>& graph,vector<bool>&visited,int src,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(q.size()>0){
            int _node=q.front();
            cout<<_node<<" ";

            q.pop();

            if(visited[_node]) continue;

            visited[_node]=true;
            for(auto neighbour:graph[_node]){
                if(visited[neighbour]) continue;

                if(color[_node]==color[neighbour]) return false;
                else{
                    color[neighbour]=(color[_node]==0)?1:0;
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool>visited(graph.size(),false);
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                if(bfs(graph,visited,i,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<vector<int>>graph={{1,3},{0,2},{1,3},{0,2}};
    cout<<s.isBipartite(graph);

    return 0;
}
