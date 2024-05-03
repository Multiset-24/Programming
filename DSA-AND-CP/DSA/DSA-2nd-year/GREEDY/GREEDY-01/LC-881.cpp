#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;

        int boat=0;
        while(i<=j){
            if(i==j){
                boat++;
                break;
            }
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            boat++;
        }
        return boat;
    }
};
int main() {
 
    return 0;
}