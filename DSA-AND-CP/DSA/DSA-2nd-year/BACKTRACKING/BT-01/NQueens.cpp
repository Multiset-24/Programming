#include <bits/stdc++.h>
using namespace std;
//leetcodelink: https://leetcode.com/problems/n-queens/
#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template<typename T>

// Function templates for reading input
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

class Solution {
public:
    vector<vector<char>>Board;
    bool canPlaceThere(int k,int j,int n){
        for(int i=0;i<n;i++){
            if(Board[i][j]=='Q') return false;
        }

        for(int p=k-1, q=j-1; p>=0 && q>=0; p--, q--){
            if(Board[p][q]=='Q') return false; 
        }
        for(int p=k+1, q=j+1;p<n && q<n;p++,q++){
            if(Board[p][q]=='Q') return false; 
        }

        for(int p=k-1, q=j+1;p>=0 && q<n;p--,q++){
            if(Board[p][q]=='Q') return false; 
        }
        for(int p=k+1, q=j-1;p<n && q>=0;p++,q--){
            if(Board[p][q]=='Q') return false; 
        }

        return true;
    }
    void helper(vector<vector<string>>&result,int k,int n){
        if(k==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    s.push_back(Board[i][j]);
                }
                temp.push_back(s);
            }
            result.push_back(temp);
            return ;
        }
            for(int j=0;j<n;j++){
                if(canPlaceThere(k,j,n)){
                    Board[k][j]='Q';
                    helper(result,k+1,n);
                    Board[k][j]='.';
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        Board.resize(n,vector<char>(n,'.'));
        helper(result,0,n);
        return result;
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    read(n);
    Solution ob;
    vector<vector<string>>ans=ob.solveNQueens(n);
    int count=0;
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<endl;
        }
        count++;
        cout<<endl;
    }

    cout<<count<<endl;
    return 0;
}