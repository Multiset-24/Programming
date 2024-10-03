#include <bits/stdc++.h>
using namespace std;
/*
---------------cycle detection using dsu -----------
*/
#define mod 1000000007
int _find(int x, vector<int> &parent)
{
    return (parent[x] == x) ? x : parent[x] = _find(parent[x], parent);
}

bool _union(int &a, int &b, vector<int> &parent, vector<int> &rank)
{
    a = _find(a, parent);
    b = _find(b, parent);
    if(a==b) return true;
    if (rank[a] > rank[b])
    {
        parent[b] = a;
    }
    else if (rank[b] > rank[a])
    {
        parent[a] = b;
    }
    else
    {
        parent[b] = a;
        rank[a]++;
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int e;
    cin >> e;

    while (e--){
        int a,b;
        cin>>a>>b;
        if(_union(a,b,parent,rank)){
            cout<<"cycle detected";
            return 0;
        }
    }
        return 0;
}