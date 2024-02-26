#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;
vector < vector<pp> >gr;
void add_edge(int a, int b, int wt, bool bidir = true)
{
    gr[a].push_back({b, wt});
    if (bidir)
    {
        gr[b].push_back({a, wt});
    }
}
class cmp{
    public:
    bool operator()(pp p1,pp p2){
        return p1.second>p2.second;
    }
};
vector<int>dijkastra(int src,int v,int e){
    vector<int>via(v,-1);
    unordered_set<int>visited;
    vector<int>key(v,INT_MAX);
    vector<int>result(v);
    priority_queue<pp,vector<pp>,cmp>pq;//first contains the node and second is the distance of that node from the source

    key[src]=0;
    pq.push({src,0});
    
    while(pq.size()>0){
        pp _top=pq.top();
        pq.pop();

        int curr=_top.first;
        int curr_distance=_top.second;

        if(visited.count(curr)) continue;

        visited.insert(curr);
        result[curr]=curr_distance;
        for(auto neighbour:gr[curr]){
            int padosi=neighbour.first;
            int padosi_ki_doori_from_curr_node=neighbour.second;

            //relaxation step

            if(!visited.count(padosi) && key[padosi]>key[curr]+padosi_ki_doori_from_curr_node){
                key[padosi]=key[curr]+padosi_ki_doori_from_curr_node;
                via[padosi]=curr;
                pq.push({padosi,key[padosi]});
            }

        }
    }

    return result;
}
int main()
{
    gr.clear();
    int v;
    cin>>v;

    gr.resize(v);

    int e;
    cin>>e;

    while(e--){
        int a,b,wt;
        cin>>a>>b>>wt;

        add_edge(a,b,wt);
    }
    int src,des;
    cin>>src>>des;
    vector<int>result=dijkastra(src,v,e);
    cout<<result[3];
    return 0;
}