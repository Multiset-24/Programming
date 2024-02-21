#include <bits/stdc++.h>
using namespace std;

//write a code to predict whethere there is a path between two nodes or not
#define mod 1000000007
vector<unordered_set<int>>graph;
int v;//no of  vertices
unordered_set<int>visited;
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

bool dfs(int start,int end){
    if(start==end) return true;

    visited.insert(start);

    for(auto neighbour : graph[start]){
        if(not visited.count(neighbour)){
            bool result=dfs(neighbour,end);
            if(result) return true;
        }
    }
     
    return false;
}

bool ispath(int start,int end){
    return dfs(start,end);
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
    int start,end;
    cin>>start>>end;
    cout<<ispath(start,end);

    display();
    return 0;



}