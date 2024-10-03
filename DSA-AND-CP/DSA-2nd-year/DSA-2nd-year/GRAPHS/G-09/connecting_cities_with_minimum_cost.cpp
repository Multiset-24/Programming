#include <bits/stdc++.h>
using namespace std;
//this question is based on kruskal's 
#define mod 1000000007
#define ll long long
//https://leetcode.ca/all/1135.html
//for the edge of the cities which has start end and weight of the edge
class Edge{
    public:

    int strt;
    int end;
    int weight;

    Edge(int strt,int end,int weight){
        this->end=end;
        this->strt=strt;
        this->weight=weight;
    }
};


//dsu functions
// 1. find function which returns the parent of the element
int _find(vector<int>&parent,int x){
    return parent[x]=(parent[x]==x)?x:_find(parent,parent[x]);
}
//2. function which basically is used to group the elements
void _union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=_find(parent,a);
    b=_find(parent,b);

    if(a!=b){
        if(rank[a]>rank[b]){
            parent[b]=a;
        }
        else if(rank[b]>rank[a]){
            parent[a]=b;
        }
        else{
            parent[b]=a;
            rank[a]++;
        }
    }
}

//custom camparator for sorting of the edge list acc to weights of the edges
bool cmp(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

vector<unordered_set<int>>graph;
void add_edge(int a,int b){
    graph[a].insert(b);
    graph[b].insert(a);
}
//function to find that the is connected or not 
bool isConnected(vector<Edge>&edges,int n){
    graph.clear();

    graph.resize(n+1,unordered_set<int>());

    for(Edge edge:edges){
        int x=edge.strt;
        int y=edge.end;

        add_edge(x,y);
    }
    vector<bool>visited(n+1,false);

    queue<int>q;
    q.push(1);
    visited[1]=true;
    visited[0]=true;//since we are not using 0 based indexing so for future uses we make it true always
    while(q.size()>0){
        int x=q.front();
        q.pop();

        for(auto ele:graph[x]){
            if(!visited[ele]){
                q.push(ele);
                visited[ele]=true;
            }
        }
    }

    for(int i=1;i<visited.size();i++){
        if(!visited[i]){
            return false;
        }
    }

    return true;
}


//kruskals to find the minimum cost to connect all cities if graph is connected
int kruskals(vector<Edge> &edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
   

    vector<int>rank(n+1,0);
    vector<int>parent(n+1);

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int edgeCount=0;//n-1
    int i=0;//to traverse the array of edges
    ll ans=0;
    while(edgeCount<n-1 and i<edges.size()){
        Edge curr=edges[i];//since we already sorted the edges acc to their weight thus we are moving greedly
        int srcpar=_find(parent,curr.strt);
        int despar=_find(parent,curr.end);

        if(srcpar!=despar){

            //since this will not make cycle we can include this in the subgraph
            _union(parent,rank,srcpar,despar);
            ans+=curr.weight;
            edgeCount++;
        }

        //no matter the edge makes the cycle or not we should move the edges vector
        i++;
    }

    return ans;
}


//Hero function
int minimum_cost_to_connect_cities(vector<Edge>&edges,int n){

    if(isConnected(edges,n)){
        return kruskals(edges,n);
    }else{
        return -1;
    }
}


int main() {
    int n;
    cin>>n;

    int e;
    cin>>e;

    vector<Edge>edges;

    while(e--){
        int strt,end,weight;

        cin>>strt>>end>>weight;
        Edge temp(strt,end,weight);
        edges.push_back(temp);

    }

    cout<<minimum_cost_to_connect_cities(edges,n);
    return 0;
}