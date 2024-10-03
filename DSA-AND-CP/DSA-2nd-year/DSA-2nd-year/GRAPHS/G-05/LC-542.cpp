#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/01-matrix/
#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        visited.clear();
        visited.resize(m, vector<bool>(n, false));
        vector<vector<int>> result(m, vector<int>(n, -1)); // resultant grid

        queue<pair<int, int>> q;

        // distance of cells containing 0 from 0 is 0 thus resultant grid's cell must have 0 distance
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
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

                if (r >= m || c >= n || r < 0 || c < 0 || visited[r][c]) continue;

                result[r][c] = result[x][y] + 1;
                visited[r][c] = true;
                q.push({r, c});
            }
        }
        return result;
    }
};

int main() {
 
    return 0;
}