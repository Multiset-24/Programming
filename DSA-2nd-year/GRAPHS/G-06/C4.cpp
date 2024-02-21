#include <bits/stdc++.h>
using namespace std;
//---------implementation of dsu using rank and path compression--------------
#define mod 1000000007
int _find(int x,vector<int>&parent){
    if(parent[x]==x) return x;
    else return parent[x]=_find(parent[x],parent);
}

void _union(int &a,int &b,vector<int>&parent,vector<int>&rank){
    a=_find(a,parent);
    b=_find(b,parent);

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
int main() {
    int n;
    cin>>n;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int query;
    cin>>query;

    while(query--){
        string s;
        cin>>s;
        if(s=="union"){
            int a,b;
            cin>>a>>b;
            _union(a,b,parent,rank);
        }
        else if(s=="find"){
            int x;
            cin>>x;
            cout<<_find(x,parent);
        }
        else{
            cout<<"Invalid operation !";
        }
    }
    return 0;
}