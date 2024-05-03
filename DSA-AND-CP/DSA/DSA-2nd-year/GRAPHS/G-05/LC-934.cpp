#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<pair<int,int>> non_border;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Find the first island and mark its cells as visited
        bool foundFirstIsland = false;
        for(int i = 0; i < m; i++) {
            if(foundFirstIsland) break;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    visited[i][j] = true;
                    q.push({i, j});
                    foundFirstIsland = true;
                    break;
                }
            }
        }

        // Breadth-first search to find the first island
        while(!q.empty()) {
            auto pair = q.front();
            q.pop();

            int x = pair.first;
            int y = pair.second;

            for(int i = 0; i < 4; i++) {
                int r = x + dir[i][0];
                int c = y + dir[i][1];

                // Check if neighboring cell is within bounds and not visited
                if(r >= 0 && c >= 0 && r < m && c < n && !visited[r][c]) {
                    visited[r][c] = true;
                    if(grid[r][c] == 1)
                        q.push({r, c}); // Add neighboring land cell to the queue
                    else
                        non_border.push_back({r, c}); // Add neighboring water cell to the non_border list
                }
            }
        }

        // Now we have the first island, we need to expand it until we find the second island
        int steps = 1;
        while(!non_border.empty()) {
            int size = non_border.size();
            for(int i = 0; i < size; i++) {
                auto pair = non_border[i];
                int x = pair.first;
                int y = pair.second;
                for(int j = 0; j < 4; j++) {
                    int r = x + dir[j][0];
                    int c = y + dir[j][1];
                    if(r >= 0 && c >= 0 && r < m && c < n && !visited[r][c]) {
                        if(grid[r][c] == 1)
                            return steps; // Found the second island, return steps
                        visited[r][c] = true;
                        non_border.push_back({r, c});
                    }
                }
            }
            non_border.erase(non_border.begin(), non_border.begin() + size); // Erase the expanded part
            steps++; // Increment steps for each expansion
        }
        return 0; // In case no second island found
    }
};
int main() {
 
    return 0;
}