#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/number-of-provinces/
#define mod 1000000007
class Solution {
public:
    vector<int>parent;
    vector<int> _size;
    void make_Set(int x){
        parent[x]=x;
        // _size[x]=1;
    }
    int _find(int x){
        if (parent[x] == x)
            return x;
        /*
              5
              |
           4--0--3        we are just making groups pointing to a single root rather than making a tree structure
             / \         
            1   2       

        */
        else
            return parent[x]=_find(parent[x]);
    }
    void _union(int a ,int b){
        int root_a = _find(a);
        int root_b = _find(b);

        if (root_a != root_b) {//we just make the root of the major group of the minor group by just making the major root node the root of minor root node of the previous one
            
            if (_size[root_a] < _size[root_b]) {
                parent[root_a] = root_b;
                _size[root_b] += _size[root_a];
            } else {
                parent[root_b] = root_a;
                _size[root_a] += _size[root_b];
            }
        }
    }
    

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.clear();
        _size.clear();
        parent.resize(n+1);
        _size.resize(n+1);
        for(int i=1;i<=n;i++){
            make_Set(i);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    _union(i+1,j+1);
                }
            }
        }

        int count=0;
        for(int i=1;i<=n;i++){
            if(parent[i]==i){
                count++;
            }
        }
        return count;
    }
};


int main() {
 
    return 0;
}