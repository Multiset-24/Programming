#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 

template<typename T>
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}


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
    
    int n,Q;
    read(n,Q);

    vector<vector<int>>board(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char forest;
            cin>>forest;
            if(forest=='.')board[i][j]=0;
            else board[i][j]=1;
        }
    }
    vector<vector<int>>prefix_sum_2d(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            prefix_sum_2d[i][j]=prefix_sum_2d[i-1][j]+prefix_sum_2d[i][j-1]-prefix_sum_2d[i-1][j-1]+board[i][j];
        }
    }

    while(Q--){
        int sx,sy,ex,ey;
        read(sx,sy,ex,ey);

        cout<<prefix_sum_2d[ex][ey]-prefix_sum_2d[sx-1][ey]-prefix_sum_2d[ex][sy-1]+prefix_sum_2d[sx-1][sy-1]<<endl;
    }
    return 0;
}