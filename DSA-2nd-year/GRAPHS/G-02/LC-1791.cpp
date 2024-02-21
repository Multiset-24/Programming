#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-center-of-star-graph/
#define mod 1000000007
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int b=edges[0][1];

        int c=edges[1][0];
        int d=edges[1][1];

        return (a==c || b==c)?c:d;
    }
};
int main() {
 
    return 0;
}