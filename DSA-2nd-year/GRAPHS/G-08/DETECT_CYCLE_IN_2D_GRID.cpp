#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/detect-cycles-in-2d-grid/description/
#define mod 1000000007
class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        
        for (auto& d : dir) {
            int r = i + d[0];
            int c = j + d[1];
            
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && !(pi == r && pj == c)) {
                if (grid[r][c] == grid[i][j]) {
                    if (visited[r][c] || dfs(r, c, i, j, grid, visited)) return true;
                }
            }
        }
        
        return false;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited)) return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
 
    return 0;
}