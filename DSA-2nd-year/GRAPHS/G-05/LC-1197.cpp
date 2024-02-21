#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-1, -2}, {-2, -1}};
    
    int bfs(int x, int y) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(8, vector<bool>(8, false)); // Assuming 8x8 chessboard

        q.push({0, 0});
        visited[0][0] = true;
        
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto pair = q.front();
                q.pop();
                int r = pair.first;
                int c = pair.second;
                if (r == x && c == y) return moves;
                for (int i = 0; i < 8; i++) {
                    int X = r + dir[i][0];
                    int Y = c + dir[i][1];
                    if (X >= 0 && X < 8 && Y >= 0 && Y < 8 && !visited[X][Y]) {
                        q.push({X, Y});
                        visited[X][Y] = true;
                    }
                }
            }
            moves++;
        }
        return -1; // Destination not reachable
    }
    
    int minKnightMoves(int x, int y) {
        return bfs(x, y);
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    Solution knight;
    cout << knight.minKnightMoves(x, y);
    return 0;
}
