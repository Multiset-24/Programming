#include <bits/stdc++.h>
using namespace std;
//weighted directional and undirectional graphs
//adjacency set


#define mod 1000000007
vector<unordered_set<int>>graph;
int v;//no of  vertices

void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].insert(dest);

    if(bi_dir){
        graph[dest].insert(src);
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
    graph.resize(v,unordered_set<int>());
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