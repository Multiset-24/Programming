#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/min-cost-to-connect-all-points/
#define mod 1000000007
#define ll long long
//class of edge which has strt and end as well as the weight of the edge 
class edge
{
public:
    int strt;
    int end;
    int weight;


    edge(int strt, int end, int weight)
    {
        this->end = end;
        this->strt =strt;
        this->weight = weight;
    }
};
//custom comparator for the edges vector 
bool cmp(edge &e1, edge &e2)
{
    return e1.weight<e2.weight;
}
class Solution {
public:


    int _find(vector<int>&parent,int x){
        return parent[x]=(parent[x]==x)?x:_find(parent,parent[x]);
    }

    void _union(int a ,int b,vector<int>&parent,vector<int>&rank){
        a=_find(parent,a);
        b=_find(parent,b);

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


    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<edge>edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int cost=abs(x2-x1)+abs(y2-y1);
                cout<<cost<<" ";
                edge e(i,j,cost);
                edges.push_back(e);
            }
        }
        cout<<endl;
        int n=points.size();

        vector<int>rank(n,0);
        vector<int>parent(n,0);
        iota(parent.begin(),parent.end(),0);
        sort(edges.begin(),edges.end(),cmp);
        int edgeCount=0;
        int min_cost=0;
        for(auto Edge:edges){
            cout<<Edge.strt<<" "<<Edge.end<<" "<<Edge.weight<<endl;
            int x_parent=_find(parent,Edge.strt);
            int y_parent=_find(parent,Edge.end);

            if(x_parent!=y_parent){
                _union(x_parent,y_parent,parent,rank);
                min_cost+=Edge.weight;
                edgeCount++;
            }

            if(edgeCount==n-1)break;
        }

        return min_cost;
    }
};
int main() {
    
}




