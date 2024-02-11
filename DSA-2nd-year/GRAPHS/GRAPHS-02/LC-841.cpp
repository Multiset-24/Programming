#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/keys-and-rooms/description/
#define mod 1000000007
class Solution {
public:
    vector<int>visited;
    void dfs(int idx,vector<vector<int>>& rooms){
        visited[idx]=1;
        for(auto n:rooms[idx]){
            if(visited[n]==0){
                dfs(n,rooms);
            
        }
    }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.clear();
        visited.resize(rooms.size(),0);

        dfs(0,rooms);

        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                return false;
            }
        }

        return true;
    }
};
int main() {
 
    return 0;
}