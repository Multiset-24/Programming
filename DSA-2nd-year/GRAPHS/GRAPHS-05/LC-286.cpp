#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
//https://leetcode.ca/all/286.html

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited;

    vector<vector<int>> wallsAndGates(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        visited.clear();
        visited.resize(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        // distance of cells containing 0 from 0 is 0 thus resultant grid's cell must have 0 distance
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto pair = q.front();
            q.pop();

            int x = pair.first;
            int y = pair.second;

            for (int i = 0; i < 4; i++) {
                int r = x + dir[i][0];
                int c = y + dir[i][1];

                if (r >= m || c >= n || r < 0 || c < 0 || visited[r][c] || grid[r][c]==-1) continue;

                grid[r][c] = grid[x][y] + 1;
                visited[r][c] = true;
                q.push({r, c});
            }
        }
        return grid;
    }
};

int main() {
    // Input grid dimensions
    int m, n;
    cout << "Enter the number of rows and columns of the grid: ";
    cin >> m >> n;

    // Input grid values
    cout << "Enter the values for the grid:" << endl;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Create solution object
    Solution sol;

    // Call wallsAndGates function
    vector<vector<int>> result = sol.wallsAndGates(grid);

    // Output the result
    cout << "Resulting grid:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}