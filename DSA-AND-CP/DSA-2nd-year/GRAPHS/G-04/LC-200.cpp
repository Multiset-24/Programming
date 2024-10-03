#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') {
            return;
        }

        grid[r][c]=-1;
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if (grid.size() == 0) return 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};

int main() {
 
    return 0;
}