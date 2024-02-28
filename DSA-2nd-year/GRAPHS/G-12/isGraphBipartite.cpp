#include <bits/stdc++.h>
using namespace std;
// this is an
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
