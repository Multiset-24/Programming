#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/triangle/
#define mod 1000000007

class Solution {
public:
    vector<vector<int>>dp;
    int f(int r,int c,vector<vector<int>>& triangle){
        if(r==triangle.size()-1) return triangle[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=triangle[r][c]+min(f(r+1,c,triangle),f(r+1,c+1,triangle));
    }

    int fbu(vector<vector<int>>& triangle){
        //ordering is from down to up since we know all the cases from bottom raw
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        //base case
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            dp[triangle.size()-1][j]=triangle[triangle.size()-1][j];
        }


        for(int r=triangle.size()-2;r>=0;r--){
                for(int c=0;c<triangle[r].size();c++){
                    dp[r][c]=triangle[r][c]+min(dp[r+1][c],dp[r+1][c+1]);
                }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp.clear();
        // dp.resize(205,vector<int>(205,-1));
        return fbu(triangle);
    }
};
int main() {
 
    return 0;
}