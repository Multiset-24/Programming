#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
//atlantic pacific vali problem
//https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};/* 
        SHORTER VERSION OF THIS

        dfs(image, r - 1, c, color, initial_color);
        dfs(image, r + 1, c, color, initial_color);
        dfs(image, r, c - 1, color, initial_color);
        dfs(image, r, c + 1, color, initial_color);
*/

    vector<vector<int>>h;//to store the heights so that i can use globally
    int row;
    int col;

    vector<vector<bool>>bfs(queue<pair<int,int>>&q){
        vector<vector<bool>>visited(row,vector<bool>(col,false));

        while(q.size()>0){
            auto pair=q.front();
            q.pop();

            int x=pair.first;
            int y=pair.second;

            visited[x][y]=1;

            for(int i=0;i<4;i++){
                int r=x+dir[i][0];
                int c=y+dir[i][1];

                if(r<0 || r>=row || c<0 || c>=col) continue;
                if(visited[r][c]==1) continue;
                if(h[r][c]<h[x][y]) continue;

                q.push({r,c});
            }
        }
        return visited;
    }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row=heights.size();
        col=heights[0].size();
        h=heights;
        
        queue<pair<int,int>>pacific;
        queue<pair<int,int>>atlantic;

        for(int i=0;i<row;i++){
            pacific.push({i,0});
            atlantic.push({i,col-1});
        }

        for(int i=1;i<col;i++){
            pacific.push({0,i});
        }

        for(int i=0;i<col-1;i++){
            atlantic.push({row-1,i});
        }

        vector<vector<bool>>atlanticbfs=bfs(atlantic);
        vector<vector<bool>>pacificbfs=bfs(pacific);
        vector<vector<int>>result;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(atlanticbfs[i][j] && pacificbfs[i][j]){
                    result.push_back({i,j});
                } 
            }
        }
        return result;
    }
};


int main() {
 
    return 0;
}