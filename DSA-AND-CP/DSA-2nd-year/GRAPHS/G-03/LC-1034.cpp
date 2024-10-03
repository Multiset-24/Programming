#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/coloring-a-border/submissions/1167636830/
#define mod 1000000007
class Solution {
public:
    vector<vector<bool>>visited;

    vector<pair<int,int>>non_border;
    void dfs(vector<vector<int>>& g, int r, int c, int col,int og){
        if(g.size()==0 ) return ;
        if(r>=g.size() || c>=g[0].size() || c<0 || r<0 || g[r][c]!=og) return ;
        if(visited[r][c]) return ;

        visited[r][c]=1;
        g[r][c]=-col;

        dfs(g,r+1,c,col,og);
        dfs(g,r-1,c,col,og);
        dfs(g,r,c+1,col,og);
        dfs(g,r,c-1,col,og);

        if (r > 0 && r < g.size() - 1 && c > 0 && c <g[0].size() - 1 &&
        g[r][c-1] == -col && g[r][c+1] ==-col &&
        g[r-1][c] == -col && g[r+1][c] == -col) {
        non_border.push_back({r, c});
     }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid.size()==0 ) return grid;
        int og=grid[row][col];
        visited.clear();
        non_border.clear();
        visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
        dfs(grid,row,col,color,og);

        for(auto pair:non_border){
            int x=pair.first;
            int y=pair.second;
            cout<<x<<" "<<y<<endl;
            grid[x][y]=og;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-color) grid[i][j]=color;
            }
        }
         return grid;
    }
};
int main() {
 
    return 0;
}