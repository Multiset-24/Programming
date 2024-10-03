#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#define print_set(s)             \
    {                            \
        cout << #s << " = {";    \
        for (auto &elem : s)     \
            cout << elem << " "; \
        cout << "}" << endl;     \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_set(s)
#define print_2dvector(v)
#endif
#define endl '\n'

// Function to check if a word is found in the grid starting from (i, j)
bool finder(const string &s, const vector<vector<char>> &grid, int i, int j, int dx, int dy,vector<pair<int,int>>&idx) {
    int n = grid.size();
    int m = grid[0].size();
    int len = s.size();
    
    for (int k = 0; k < len; ++k) {
        int x = i + k * dx;
        int y = j + k * dy;

        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != s[k]) {
            return false;
        }

        idx.push_back({x,y});
    }
    return true;
}

void jarvis() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w, '.'));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    string s = "snuke";
    string t = "ekuns";

    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {1, 0}, {0, 1}};

    bool found = false;
    for (int i = 0; i < h && !found; ++i) {
        for (int j = 0; j < w && !found; ++j) {
            vector<pair<int,int>>idx;
            if (grid[i][j] == 's') {
                for (auto dir : directions) {
                    if (finder(s, grid, i, j, dir.first, dir.second,idx)) {
                        for(auto index:idx){
                            cout<<index.first+1<<" "<<index.second+1<<endl;
                        }
                        return;
                    }
                    idx.clear();
                }
            } else if (grid[i][j] == 'e') {
                for (auto dir : directions) {
                    if (finder(t, grid, i, j, dir.first, dir.second,idx)) {
                        reverse(idx.begin(),idx.end());
                       for(auto index:idx){
                            cout<<index.first+1<<" "<<index.second+1<<endl;
                        }
                        return;
                    }
                    idx.clear();
                }
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--) {
        jarvis();
    }
    return 0;
}
