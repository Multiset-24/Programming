#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int maze[7][7];

string s;

int res(int i, int j, int level) {
    if (i == 6 && j == 0)
    {
        if (level != 48) return 0;
        return 1;
    }
    if (i < 0 || i >= 7 || j < 0 || j >= 7 || maze[i][j]) return 0;

    // Detect deadlock: no further moves possible
    if (
        ((i + 1 >= 7 || maze[i + 1][j]) && (i - 1 < 0 || maze[i - 1][j]) &&
         j - 1 >= 0 && j + 1 < 7 && !maze[i][j - 1] && !maze[i][j + 1]) ||
        ((j + 1 >= 7 || maze[i][j + 1]) && (j - 1 < 0 || maze[i][j - 1]) &&
         i - 1 >= 0 && i + 1 < 7 && !maze[i - 1][j] && !maze[i + 1][j])
    ) {
        return 0;
    }

    maze[i][j] = 1;

    int cnt = 0;

    if (s[level] == '?') {
        for (int k = 0; k < 4; k++) {
            int r = i + dir[k][0];
            int c = j + dir[k][1];

            cnt += res(r, c, level + 1);
        }
    }
    else {
        if (s[level] == 'U') {
            cnt += (i-1<0)?0:res(i - 1, j, level + 1);
        }
        else if (s[level] == 'D') {
            cnt += (i+1>=7)?0:res(i + 1, j, level + 1);
        }
        else if (s[level] == 'L') {
            cnt += (j-1<0)?0:res(i, j - 1, level + 1);
        }
        else if (s[level] == 'R') {
            cnt += (j+1>=7)?0:res(i, j + 1, level + 1);
        }
    }

    maze[i][j] = 0;

    return cnt;
}

void jarvis() {
    cin >> s;
    memset(maze, 0, sizeof(maze));

    int ways = res(0, 0, 0);

    cout << ways << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    while (q--) {
        jarvis();
    }
    return 0;
}
