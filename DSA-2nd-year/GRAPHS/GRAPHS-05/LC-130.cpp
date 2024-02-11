#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/surrounded-regions/
#define mod 1000000007
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited;
        visited.resize(m,vector<bool>(n,false));
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((j==0 || i==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='-';
                    visited[i][j]=true;
                }
            }
        }

        while(q.size()>0){
            auto pair=q.front();
            q.pop();

            int x=pair.first;
            int y=pair.second;
            visited[x][y]=true;
            for(int i=0;i<4;i++){
                int r=x+dir[i][0];
                int c=y+dir[i][1];

                if(r>=m || c>=n || r<0 || c<0 || board[r][c]!='O'|| visited[r][c]) continue;
                board[r][c]='-';
                q.push({r,c});
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
            }
        }
    }
};
int main() {
 
    return 0;
}