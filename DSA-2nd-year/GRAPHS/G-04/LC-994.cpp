#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/rotting-oranges/
#define mod 1000000007
class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        q.push({-1,-1});
        int  minutes=0;
        while(q.size()>0){
            auto pair=q.front();
            q.pop();

            int x=pair.first;
            int y=pair.second;
            if(x==-1 && y==-1){
                if(q.size()!=0){
                    minutes++;
                    q.push({-1,-1});
                }
                else{
                    break;
                }
            }
            else{
            for(int i=0;i<4;i++){
                int r=x+dir[i][0];
                int c=y+dir[i][1];
                cout<<r<<" "<<c<<endl;
                if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size())continue;
                if(grid[r][c]==0 || grid[r][c]==2) continue;
                grid[r][c]=2;
                q.push({r,c});
            }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return minutes;
    }
};


int main() {
 
    return 0;
}