#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/flood-fill/
//flood fill algorithm...
#define mod 1000000007
class Solution {
public: 
    void dfs(vector<vector<int>>& image, int curr_row, int curr_col, int color,int initial_color){
        int n=image.size();
        int m=image[0].size();

        if(curr_row>=n || curr_col >=m || curr_row<0 || curr_col<0){
            return ;
        }
        
        if(image[curr_row][curr_col]!=initial_color) return ;

        image[curr_row][curr_col]=color;

        dfs(image,curr_row-1,curr_col,color,initial_color);
        dfs(image,curr_row+1,curr_col,color,initial_color);
        dfs(image,curr_row,curr_col-1,color,initial_color);
        dfs(image,curr_row,curr_col+1,color,initial_color);

        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        
        int initial_color=image[sr][sc];

        dfs(image,sr,sc,color,initial_color);

        return image;
    }
};
int main() {
 
    return 0;
}