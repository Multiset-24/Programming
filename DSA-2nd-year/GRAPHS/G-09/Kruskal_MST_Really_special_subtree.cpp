#include <bits/stdc++.h>
using namespace std;
// https://www.hackerrank.com/challenges/kruskalmstrsub/problem
#define mod 1000000007
#define ll long long

//dsu functions
int _find(vector<int>&parent,int x){
    return parent[x]=(parent[x]==x)?x:_find(parent,parent[x]);
}
void _union(vector<int>&parent,vector<int>&rank,int  a ,int b){
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
    else{
        return ;
    }
}


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


int kruskals(vector<edge> &edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
   

    vector<int>rank(n,0);
    vector<int>parent(n);

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int edgeCount=0;//n-1
    int i=0;//to traverse the array of edges
    ll ans=0;
    while(edgeCount<n-1 and i<edges.size()){
        edge curr=edges[i];//since we already sorted the edges acc to their weight thus we are moving greedly
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
int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;

    vector<edge>edges;

    for(int i=0;i<e;i++){
        int strt,end,weight;

        cin>>strt>>end>>weight;

        edge e(strt,end,weight);

        edges.push_back(e);

    }

    cout<<kruskals(edges,n);
    return 0;
}