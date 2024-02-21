#include <bits/stdc++.h>
using namespace std;
//unweighted directional and undirectional graphs
//adjacency list 

#define mod 1000000007
vector<list<int>>graph;
int v;//no of  vertices

void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);

    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";

        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        cout<<endl;
    }
}
int main() {
    cin>>v;
    graph.clear();
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    display();

    return 0;
}