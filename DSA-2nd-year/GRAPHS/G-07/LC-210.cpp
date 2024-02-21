#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/course-schedule-ii/
#define mod 1000000007
class Solution {
public:

    vector<unordered_set<int>>graph;

    //for converting into graph where a->b represent a must completed first to go to b
    void graph_banao(vector<vector<int>>&prerequisites){
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][1];
            int b=prerequisites[i][0];

            add_edge(a,b);
        }
    }
//function to add edge
    void add_edge(int a,int b,bool dir=true){
        graph[a].insert(b);
        if(!dir){
            graph[b].insert(a);
        }
    }

//function for topological sort which solves dependency array
    void topobfs(vector<int>&result,int numCourses){
        vector<int>indegree(numCourses,0);

        unordered_set<int>visited;

        for(int i=0;i<numCourses;i++){

            for(auto neighbour:graph[i]){
                cout<<neighbour<<" ";
                indegree[neighbour]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }

        while(q.size()>0){
            int node=q.front();
            q.pop();

            result.push_back(node);

            for(auto neighbour:graph[node]){
                if(not visited.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.clear();
        graph.resize(numCourses,unordered_set<int>());
        graph_banao(prerequisites);
        vector<int>result;

        topobfs(result,numCourses);

        if(result.size()==numCourses) return result;
        else{
            result.clear();
            return result;
        };
    }
};
int main() {
 
    return 0;
}