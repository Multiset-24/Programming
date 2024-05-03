#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 

// Function templates for reading input
template<typename T>
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Read the size of the board and the number of queries
    int n,Q;
    read(n,Q);

    // Initialize the board
    vector<vector<int>>board(n+1,vector<int>(n+1));

    // Read the board from input
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char forest;
            cin>>forest;
            // If the cell is a forest, mark it as 1, otherwise 0
            if(forest=='.')board[i][j]=0;
            else board[i][j]=1;
        }
    }

    // Initialize the 2D prefix sum array
    vector<vector<int>>prefix_sum_2d(n+1,vector<int>(n+1,0));

    // Calculate the 2D prefix sum
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // The value at each cell is the sum of the cell above it, to its left, and its own value, minus the cell diagonally above and to the left
            prefix_sum_2d[i][j]=prefix_sum_2d[i-1][j]+prefix_sum_2d[i][j-1]-prefix_sum_2d[i-1][j-1]+board[i][j];
        }
    }

    // Process each query
    while(Q--){
        // Read the coordinates of the top left and bottom right corners of the sub-matrix
        int sx,sy,ex,ey;
        read(sx,sy,ex,ey);

        // The sum of the sub-matrix is the sum of the cells up to (ex, ey), minus the cells up to (sx-1, ey) and (ex, sy-1), plus the cells up to (sx-1, sy-1) (to avoid double subtraction)
        cout<<prefix_sum_2d[ex][ey]-prefix_sum_2d[sx-1][ey]-prefix_sum_2d[ex][sy-1]+prefix_sum_2d[sx-1][sy-1]<<endl;
    }
    return 0;
}