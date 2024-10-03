/*---------------------------------------------------------------------------------------------------
Saurav: Hello Jarvis !!
    ￣￣\　　　　　　　 ∧＿∧    Jarvis: Hello Master !! JAI BAJARANG BALI
　　 　  \　 ∧＿∧ 　（´<_｀ ）/￣￣    Give me some sunshine, give me some rain give me another chance to
　　　　 （ ´_ゝ`）　/　 ⌒|           Grow up once again...
　　　　／　　　＼　 　  |　|           sab moh maya hai...
　　　 /　　 /￣￣￣￣/　　|             waiting....
　 ＿_(__ﾆつ/　   _ / .| .|＿＿＿＿
　　　　＼/_______/　（u　⊃
---------------------------------------------------------------------------------------------------*/
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

// Directions for DFS
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// DFS to mark cells
void dfs(int i, int j, int dis, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    // Mark the current cell as '.'
    grid[i][j] = '.';
    if (dis <= 0)
        return; 
    for (int k = 0; k < 4; k++)
    {
        int r = i + directions[k][0];
        int c = j + directions[k][1];

        
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            (grid[r][c] <= '9' && grid[r][c] >= '1') || visited[r][c])
        {
            continue;
        }


        visited[r][c] = true;
        dfs(r, c, dis - 1, grid, visited);
        visited[r][c] = false;
    }
}

void jarvis()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    // Input the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '#' && grid[i][j] != '.')
            {
                dfs(i, j, grid[i][j] - '0', grid, visited);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // Uncomment below line for multiple test cases
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}

/* MISTAKES TO AVOID:
1. Solve problems slightly above your level to push your limits.
2. Ensure that variables are initialized before using them to avoid 'bad_alloc' errors.
3. Use max/min functions with the same types (e.g., both parameters should be of the same data type).
4. Take all inputs first, then apply logic. Avoid premature logic application, as seen in problems like CF 1685A.
5. Be mindful of memory limits when using large global/local variables.
6. Think of subarray approaches instead of brute force when appropriate.
7. Avoid floating-point errors by using integer operations when possible.
8. Watch for loop boundaries; ensure proper increment/decrement.
9. Stress test your code while debugging for edge cases.
10. Use prefix sum arrays for optimized subarray queries.
*/
