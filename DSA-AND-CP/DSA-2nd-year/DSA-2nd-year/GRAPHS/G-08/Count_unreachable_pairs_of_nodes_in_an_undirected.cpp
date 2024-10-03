#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
#define mod 1000000007
class Solution {
public:

    long long _find(int x,vector<long long>&parent){
        return (parent[x]==x)?x:parent[x]=_find(parent[x],parent);
    }

    void _union(long long a,long long b,vector<long long>&parent,vector<long long>&rank){
        a=_find(a,parent);
        b=_find(b,parent);

        if(a!=b){
            if(rank[a]>rank[b]){
                parent[b]=a;
            }
            else if(rank[a]<rank[b]){
                parent[a]=b;
            }
            else{
                parent[b]=a;
                rank[a]++;
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //approach is to find somehow the number of connected components along with the number of nodes present in them respectively
        //then we create a just have multiply number of nodes present in two any two components to find the number of edges which are not there between them which could have been there .
        // we do this for each components and sum of those edges gives us the answer
        //try using dsu that would be more easy to implement in this question rather using the dfs or bfs
        vector<long long>parent(n);
        vector<long long>rank(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto ele:edges){
            _union(ele[0],ele[1],parent,rank);
        }
        
        unordered_map<int,int>mp;

        for(int i=0;i<parent.size();i++){
            mp[parent[i]]++;
        }

        for(int i=0;i<parent.size();i++){
            cout<<parent[i]<<" ";
        }

          vector<long long> components_node(n, 0);
        for(int i = 0; i < n; i++){
            components_node[_find(i, parent)]++;
        }
        //good approach to count this all pair that are not reachable
        // Calculate the result
        long long result = 0;
        for(int i = 0; i < n; i++){
            result += (n - components_node[i]) * components_node[i];
        }
        return result / 2;
    }
    
};
int main() {
 
    return 0;
}